package com.yong.rtsp

import android.app.Service
import android.content.Intent
import android.os.IBinder

class RTSPServerService : Service() {
    private var gstreamerUtil: GstreamerUtil? = null
    override fun onCreate() {
        super.onCreate()
        gstreamerUtil = GstreamerUtil()
    }
    override fun onStartCommand(intent: Intent?, flags: Int, startId: Int): Int {
        Thread {
            Runnable {
                gstreamerUtil!!.startRtspServer()
            }.run()
        }.start()
        return START_STICKY
    }

    override fun onDestroy() {
        super.onDestroy()
        gstreamerUtil!!.stopRtspServer()
    }

    override fun onBind(intent: Intent): IBinder? {
        return null
    }
}