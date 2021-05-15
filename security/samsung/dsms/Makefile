#
# Makefile for the DSMS
#

obj-$(CONFIG_SECURITY_DSMS) := dsms_kernel_api.o
obj-$(CONFIG_SECURITY_DSMS) += dsms_access_control.o
obj-$(CONFIG_SECURITY_DSMS) += dsms_rate_limit.o
obj-$(CONFIG_SECURITY_DSMS) += dsms_policy.o
obj-$(CONFIG_SECURITY_DSMS) += dsms_init.o
obj-$(CONFIG_SECURITY_DSMS) += dsms_debug.o

ccflags-y := -Wformat

EXTRA_CFLAGS += -DDSMS_WHITELIST_IGNORE_NAME_SUFFIXES_ENABLE

# Debugging options:

ifneq (,$(filter userdebug eng, $(TARGET_BUILD_VARIANT)))
#    CFLAGS_dsms_debug.o := -DDEBUG
endif

ifneq ($(CONFIG_KUNIT), y)
    EXTRA_CFLAGS += -D__visible_for_testing=static
endif

GCOV_PROFILE := $(CONFIG_KUNIT)
ifeq ($(CONFIG_KUNIT), y)
obj-y += test/
endif
