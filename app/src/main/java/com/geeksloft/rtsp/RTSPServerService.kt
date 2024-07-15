package com.geeksloft.rtsp

import android.app.Service
import android.content.Intent
import android.os.IBinder

class RTSPServerService : Service() {
    override fun onBind(intent: Intent): IBinder? {
        return null
    }
}