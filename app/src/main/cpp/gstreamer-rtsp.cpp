#include <jni.h>
#include <string>

#include <android/log.h>
#include <gst/gst.h>
#include <gst/rtsp-server/rtsp-server.h>

#define LOG_TAG "NDK LOG"
#define LOG_I(...) __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOG_E(...) __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__)

static GMainLoop *loop;
static gboolean
timeout (GstRTSPServer * server)
{
    GstRTSPSessionPool *pool;

    pool = gst_rtsp_server_get_session_pool (server);
    gst_rtsp_session_pool_cleanup (pool);
    g_object_unref (pool);

    return TRUE;
}

extern "C" JNIEXPORT void JNICALL
Java_com_geeksloft_rtsp_GstreamerUtil_startRtspServer(JNIEnv* env, jobject)
{
    LOG_I("Starting RTSP Server");
    gst_init(NULL, NULL);

    loop = g_main_loop_new(NULL, FALSE);

    GstRTSPServer *server = gst_rtsp_server_new();
    GstRTSPMediaFactory *factory = gst_rtsp_media_factory_new();

    gst_rtsp_media_factory_set_launch(factory, "( videotestsrc ! x264enc ! rtph264pay name=pay0 pt=96 )");
    gst_rtsp_server_attach(server, NULL);

    g_timeout_add_seconds(2, (GSourceFunc) timeout, server);

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
