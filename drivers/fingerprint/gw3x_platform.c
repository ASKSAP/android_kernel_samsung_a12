#include "fingerprint.h"
#include "gw3x_common.h"
#ifdef ENABLE_SENSORS_FPRINT_SECURE
#include <linux/platform_data/spi-mt65xx.h>
#endif

int gw3x_register_platform_variable(struct gf_device *gf_dev)
{
	int retval = 0;

	pr_info("Entry\n");
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	gf_dev->fp_parent_clk = devm_clk_get(gf_dev->dev, "parent-clk");
	if (IS_ERR(gf_dev->fp_parent_clk)) {
		pr_err("Failed to get parent-clk\n");
		return PTR_ERR(gf_dev->fp_parent_clk);
	}

	gf_dev->fp_spi_pclk = devm_clk_get(gf_dev->dev, "sel-clk");
	if (IS_ERR(gf_dev->fp_spi_pclk)) {
		pr_err("Failed to get sel-clk\n");
		return PTR_ERR(gf_dev->fp_spi_pclk);
	}

	gf_dev->fp_spi_sclk = devm_clk_get(gf_dev->dev, "spi-clk");
	if (IS_ERR(gf_dev->fp_spi_sclk)) {
		pr_err("Failed to get spi-clk\n");
		return PTR_ERR(gf_dev->fp_spi_sclk);
	}
	retval = clk_set_parent(gf_dev->fp_spi_pclk, gf_dev->fp_parent_clk);
	if (retval < 0) {
		pr_err("Failed to clk_set_parent (%d)\n", retval);
	}
	pr_info("Clock preparation done : %d\n", retval);
#endif
	return retval;
}

int gw3x_unregister_platform_variable(struct gf_device *gf_dev)
{
	int retval = 0;

	pr_info("Entry\n");
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	clk_put(gf_dev->fp_parent_clk);
	clk_put(gf_dev->fp_spi_pclk);
	clk_put(gf_dev->fp_spi_sclk);
#endif

	return retval;
}

void gw3x_spi_setup_conf(struct gf_device *gf_dev, u32 bits)
{
#ifndef ENABLE_SENSORS_FPRINT_SECURE
	gf_dev->spi->bits_per_word = 8;
	if (gf_dev->prev_bits_per_word != gf_dev->spi->bits_per_word) {
		if (spi_setup(gf_dev->spi))
			pr_err("failed to setup spi conf\n");
		pr_info("prev-bpw:%d, bpw:%d\n",
				gf_dev->prev_bits_per_word, gf_dev->spi->bits_per_word);
		gf_dev->prev_bits_per_word = gf_dev->spi->bits_per_word;
	}
#endif
}

#ifdef ENABLE_SENSORS_FPRINT_SECURE
static int gw3x_sec_spi_prepare(struct gf_device *gf_dev)
{
	u32 clk_speed = gf_dev->spi_speed;
	int retval = 0;
	pr_info("Clk_speed : %u\n", clk_speed);
	retval = clk_prepare_enable(gf_dev->fp_spi_sclk);
	if (clk_get_rate(gf_dev->fp_spi_sclk) != gf_dev->spi_speed * SPI_CLK_DIV_MTK) {
		retval = clk_set_rate(gf_dev->fp_spi_sclk, gf_dev->spi_speed * SPI_CLK_DIV_MTK);
		if (retval < 0)
			pr_info("SPI clk set failed : %d, %d\n", retval, gf_dev->spi_speed);
		else
			pr_info("Set SPI clock rate0 : %u (%lu)\n",
				clk_speed, clk_get_rate(gf_dev->fp_spi_sclk) / SPI_CLK_DIV_MTK);
	}
	else {
		pr_info("Set SPI clock rate1 : %u (%lu)\n",
			clk_speed, clk_get_rate(gf_dev->fp_spi_sclk) / SPI_CLK_DIV_MTK);
	}
	return retval;
}

static int gw3x_sec_spi_unprepare(struct gf_device* gf_dev)
{
	clk_disable_unprepare(gf_dev->fp_spi_sclk);
	return 0;
}
#endif

int gw3x_spi_clk_enable(struct gf_device *gf_dev)
{
	int retval = 0;
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	if (!gf_dev->enabled_clk) {
		retval = gw3x_sec_spi_prepare(gf_dev);
		if (retval < 0)
			pr_err("Unable to enable spi clk\n");
		else
			pr_info("ENABLE_SPI_CLOCK %d\n", gf_dev->spi_speed);
		__pm_stay_awake(gf_dev->wake_lock);
		gf_dev->enabled_clk = true;
	}
#endif
	return retval;
}

int gw3x_spi_clk_disable(struct gf_device *gf_dev)
{
	int retval = 0;
#ifdef ENABLE_SENSORS_FPRINT_SECURE
	pr_info("FP_DISABLE_SPI_CLOCK\n");
	if (gf_dev->enabled_clk) {
		retval = gw3x_sec_spi_unprepare(gf_dev);
		if (retval < 0)
			pr_err("couldn't disable spi clks\n");
		__pm_relax(gf_dev->wake_lock);
		gf_dev->enabled_clk = false;
		pr_debug("clk disalbed\n");
	}
#endif
	return retval;
}

int gw3x_set_cpu_speedup(struct gf_device *gf_dev, int onoff)
{
	int retval = 0;

#if 0
#if defined(CONFIG_TZDEV_BOOST) && defined(ENABLE_SENSORS_FPRINT_SECURE)
	if (onoff) {
		pr_info("SPEEDUP ON:%d\n", onoff);
		tz_boost_enable();
	} else {
		pr_info("SPEEDUP OFF:%d\n", onoff);
		tz_boost_disable();
	}
#endif
#else
	pr_info("FP_CPU_SPEEDUP does not set\n");
#endif
	return retval;
}

int gw3x_pin_control(struct gf_device *gf_dev, bool pin_set)
{
	int status = 0;
	pr_info("Pin control entry");
	gf_dev->p->state = NULL;
	if (pin_set) {
		if (!IS_ERR(gf_dev->pins_poweron)) {
			status = pinctrl_select_state(gf_dev->p, gf_dev->pins_poweron);
			if (status)
				pr_err("can't set pin default state\n");
			pr_info("idle\n");
		}
	} else {
		if (!IS_ERR(gf_dev->pins_poweroff)) {
			status = pinctrl_select_state(gf_dev->p, gf_dev->pins_poweroff);
			if (status)
				pr_err("can't set pin sleep state\n");
			pr_info("sleep\n");
		}
	}
	return status;
}
