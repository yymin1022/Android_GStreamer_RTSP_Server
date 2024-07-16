package com.yong.rtsp

import android.content.Intent
import android.os.Bundle
import android.view.View
import android.widget.Button
import androidx.activity.enableEdgeToEdge
import androidx.appcompat.app.AppCompatActivity
import androidx.core.view.ViewCompat
import androidx.core.view.WindowInsetsCompat

class MainActivity : AppCompatActivity() {
    private var btnStart: Button? = null
    private var btnStop: Button? = null

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        enableEdgeToEdge()
        setContentView(R.layout.activity_main)
        ViewCompat.setOnApplyWindowInsetsListener(findViewById(R.id.main)) { v, insets ->
            val systemBars = insets.getInsets(WindowInsetsCompat.Type.systemBars())
            v.setPadding(systemBars.left, systemBars.top, systemBars.right, systemBars.bottom)
            insets
        }

        btnStart = findViewById(R.id.main_btn_start_server)
        btnStop = findViewById(R.id.main_btn_stop_server)

        btnStart!!.setOnClickListener(btnListener)
        btnStop!!.setOnClickListener(btnListener)
    }

    private val btnListener = View.OnClickListener {
        when(it.id) {
            R.id.main_btn_start_server -> startService(Intent(applicationContext, RTSPServerService::class.java))
            R.id.main_btn_stop_server -> stopService(Intent(applicationContext, RTSPServerService::class.java))
        }
    }
}