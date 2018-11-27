package org.shaswata.project;

import java.lang.String;
import java.lang.InterruptedException;

class ThreadClass extends Thread {
    private Thread t;
    private String threadName;

    ThreadClass(String name) {
        threadName = name;
        System.out.println("Creating " +  threadName );
    }

    public void run() {
        System.out.println("Running " +  threadName );
        try {
            for(int i = 100; i > 0; i--) {
                System.out.println("Thread: " + threadName + ", " + i);
                Thread.sleep(1);
            }
        } catch (InterruptedException e) {
            System.out.println("Thread " +  threadName + " interrupted.");
        }
        System.out.println("Thread " +  threadName + " exiting.");
    }

    public void start () {
        System.out.println("Starting " +  threadName );
        if (t == null) {
            t = new Thread (this, threadName);
            t.start ();
        }
    }
}