/*
 * Samsung Elec.
 *
 * drivers/gpio/secgpio_dvs_mt.c - Read GPIO for MT6768 of MTK
 *
 * Copyright (C) 2016, Samsung Electronics.
 *
 * This program is free software. You can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation
 */

#include <linux/platform_device.h>
#include <linux/errno.h>
#include <linux/sec-pinmux.h>
#include "gpiolib.h"
#include "../pinctrl/mediatek/pinctrl-mtk-common.h"

/* GPIO Number of MT6765 */
#define AP_GPIO_COUNT   179

#define GET_RESULT_GPIO(a, b, c)        \
	((a<<4 & 0xF0) | (b<<1 & 0xE) | (c & 0x1))

static const char *pinctrl_paris_modname = "1000b000.pinctrl";

static unsigned char checkgpiomap_result[GDVS_PHONE_STATUS_MAX][AP_GPIO_COUNT];
static struct gpiomap_result gpiomap_result = {
	.init = checkgpiomap_result[PHONE_INIT],
	.sleep = checkgpiomap_result[PHONE_SLEEP]
};

/*
 **************************************************************
  Pre-defined variables. (DO NOT CHANGE THIS!!)
  static unsigned char checkgpiomap_result[GDVS_PHONE_STATUS_MAX][AP_GPIO_COUNT];
  static struct gpiomap_result gpiomap_result = {
  .init = checkgpiomap_result[PHONE_INIT],
  .sleep = checkgpiomap_result[PHONE_SLEEP]
  };
 **************************************************************
 */
static void mt_check_gpio_status(unsigned char phonestate)
{
	struct gpio_device *gdev;
	struct gpio_chip *chip = NULL;
	unsigned long flags;
	unsigned int i;

	struct gpiomux_setting val;
	int temp_io = 0, temp_pupd = 0, temp_level = 0;

	spin_lock_irqsave(&gpio_lock, flags);
	list_for_each_entry(gdev, &gpio_devices, list) {
		chip = gdev->chip;
		if (strncmp(pinctrl_paris_modname, chip->label,
				strlen(pinctrl_paris_modname)) == 0)
			break;
	}

	for (i = 0; i < AP_GPIO_COUNT ; i++) {
		temp_io = 0;
		temp_pupd = 0;
		temp_level = 0;

		val.func = mtk_pinmux_get(chip, i);
		val.dir = !mtk_gpio_get_direction(chip, i);
		val.pull_en = mtk_pullen_get(chip, i);
		val.pull = mtk_pullsel_get(chip, i);
		val.pull = val.pull >= 0 ? val.pull & 0x01 : -1;

		/* Check Pin-Mux Configuration */
		switch (val.func) {
		case GPIOMUX_FUNC_GPIO:
			switch (val.dir) {
			case GPIOMUX_IN:
				temp_io = GDVS_IO_IN;
				temp_level = mtk_gpio_get_in(chip, i);
				break;
			case GPIOMUX_OUT:
				temp_io = GDVS_IO_OUT;
				temp_level = mtk_gpio_get_out(chip, i);
				break;
			default:
				temp_io = GDVS_IO_ERR;
				break;
			}
			break;
		case GPIOMUX_FUNC_1:
		case GPIOMUX_FUNC_2:
		case GPIOMUX_FUNC_3:
		case GPIOMUX_FUNC_4:
		case GPIOMUX_FUNC_5:
		case GPIOMUX_FUNC_6:
		case GPIOMUX_FUNC_7:
			temp_io = GDVS_IO_FUNC;
			break;
		default:
			temp_io = GDVS_IO_ERR;
			break;
		}

		/* Check Pull Configuration */
		switch (val.pull_en) {
		case GPIOMUX_PULL_DIS:
		case GPIOMUX_PULL_NONE:
			temp_pupd = GDVS_PUPD_NP;
			break;
		case GPIOMUX_PULL_EN:
		case GPIOMUX_PULL1:
		case GPIOMUX_PULL2:
		case GPIOMUX_PULL3:
			switch (val.pull) {
			case GPIOMUX_PULL_DOWN:
				temp_pupd = GDVS_PUPD_PD;
				break;
			case GPIOMUX_PULL_UP:
				temp_pupd = GDVS_PUPD_PU;
				break;
			default:
				temp_pupd = GDVS_PUPD_ERR;
				break;
			}
			break;
		default:
			temp_pupd = GDVS_PUPD_ERR;
		}

		checkgpiomap_result[phonestate][i] =
		(unsigned char)GET_RESULT_GPIO(temp_io, temp_pupd, temp_level);
	}
	spin_unlock_irqrestore(&gpio_lock, flags);
}

static void check_gpio_status(unsigned char phonestate)
{
	pr_info("[secgpio_dvs][%s] state : %s\n", __func__,
			(phonestate == PHONE_INIT) ? "init" : "sleep");

	mt_check_gpio_status(phonestate);
}

static struct gpio_dvs mt_gpio_dvs = {
	.result = &gpiomap_result,
	.check_gpio_status = check_gpio_status,
	.count = AP_GPIO_COUNT,
};

struct platform_device secgpio_dvs_device = {
	.name   = "secgpio_dvs",
	.id             = -1,
	/*
	 ***************************************************************
	   Designate appropriate variable pointer
	   in accordance with the specification of each BB vendor.
	 ***************************************************************
	 */
	.dev.platform_data = &mt_gpio_dvs,
};

static struct platform_device *secgpio_dvs_devices[] __initdata = {
	&secgpio_dvs_device,
};

static int __init secgpio_dvs_device_init(void)
{
	return platform_add_devices(
			secgpio_dvs_devices, ARRAY_SIZE(secgpio_dvs_devices));
}
arch_initcall(secgpio_dvs_device_init);
