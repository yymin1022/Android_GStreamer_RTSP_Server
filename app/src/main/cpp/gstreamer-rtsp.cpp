#include <jni.h>
#include <string>

#include <android/log.h>

#define LOG_TAG "NDK LOG"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

extern "C" JNIEXPORT void JNICALL
Java_com_geeksloft_rtsp_MainActivity_startRtspServer(JNIEnv* env, jobject)
{
    LOG_I("Start RTSP Server");
}

extern "C" JNIEXPORT void JNICALL
Java_com_geeksloft_rtsp_MainActivity_stopRtspServer(JNIEnv* env, jobject)
{
    LOG_I("Stop RTSP Server");
}
