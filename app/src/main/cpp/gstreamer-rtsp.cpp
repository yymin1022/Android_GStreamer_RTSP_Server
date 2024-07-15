#include <jni.h>
#include <string>

#include <android/log.h>
#include <gst/gst.h>

#define LOG_TAG "NDK LOG"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static GMainLoop *loop;

extern "C" JNIEXPORT void JNICALL
Java_com_geeksloft_rtsp_GstreamerUtil_startRtspServer(JNIEnv* env, jobject)
{
    LOG_I("Starting RTSP Server");
    gst_init(NULL, NULL);

    loop = g_main_loop_new(NULL, FALSE);

    g_main_loop_run(loop);
    LOG_I("Started RTSP Server");
}

extern "C" JNIEXPORT void JNICALL
Java_com_geeksloft_rtsp_GstreamerUtil_stopRtspServer(JNIEnv* env, jobject)
{
    LOG_I("Stopping RTSP Server");
    if (loop != NULL)
    {
        g_main_loop_quit(loop);
        loop = NULL;
        LOG_I("Stopped RTSP Server");
    }
}
