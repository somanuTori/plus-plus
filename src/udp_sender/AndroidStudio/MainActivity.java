package com.example.udp_listener;

import android.app.Activity;
import android.os.Looper;
import android.util.Log;
import android.widget.Toast;

import java.net.DatagramPacket;
import java.net.DatagramSocket;

public class UDPReceiver implements Runnable {

    private final Activity activity;
    private final int port;
    private boolean running = true;

    public UDPReceiver(Activity activity, int port) {
        this.activity = activity;
        this.port = port;
        Log.d("UDP", "Received: $message from ${packet.address}");


    }

    @Override
    public void run() {
        try {
            DatagramSocket socket = new DatagramSocket(port);
            byte[] buffer = new byte[1024];

            while (running) {
                DatagramPacket packet =
                        new DatagramPacket(buffer, buffer.length);

                socket.receive(packet);

                String msg = new String(
                        packet.getData(),
                        0,
                        packet.getLength()
                );

                activity.runOnUiThread(() ->
                        Toast.makeText(
                                activity,
                                msg,
                                Toast.LENGTH_LONG
                        ).show()
                );
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    public void stop() {
        running = false;
    }
}
