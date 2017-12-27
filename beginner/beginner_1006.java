package beginner;

import java.io.*;
import java.util.*;
import java.lang.*;
public class beginner_1006 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        System.out.printf("MEDIA = %.1f\n", (2*a + 3*b + 5*c)/10);
    }

}
