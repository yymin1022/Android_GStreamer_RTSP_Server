package com.yong.rtsp

class GstreamerUtil {
    companion object {
        init {
            System.loadLibrary("gstreamer-rtsp")
        }
    }

    external fun startRtspServer()
    external fun stopRtspServer()
}