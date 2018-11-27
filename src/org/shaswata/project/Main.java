package org.shaswata.project;

import java.lang.String;

public class Main {

    public static void main(String args[]) {
        System.out.println("Thread Main starting.");

        ThreadClass T1 = new ThreadClass("Thread-1");
        T1.start();

        ThreadClass T2 = new ThreadClass("Thread-2");
        T2.start();

        ThreadClass T3 = new ThreadClass("Thread-3");
        T3.start();

        ThreadClass T4 = new ThreadClass("Thread-4");
        T4.start();
    }
}
