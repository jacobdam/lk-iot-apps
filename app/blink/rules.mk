LOCAL_DIR := $(GET_LOCAL_DIR)

MODULE := $(LOCAL_DIR)

MODULE_SRCS += \
    $(LOCAL_DIR)/blink.c \

MODULE_ARM_OVERRIDE_SRCS := \

include make/module.mk
