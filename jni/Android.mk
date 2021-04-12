# https://developer.android.com/ndk/guides/android_mk
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)

LOCAL_MODULE := AndroidWebServer
LOCAL_SRC_FILES := ../main.cpp ../mongoose.c
LOCAL_CFLAGS += -fPIE
LOCAL_LDFLAGS += -fPIE -pie
LOCAL_CPP_FEATURES := exceptions

include $(BUILD_EXECUTABLE)
