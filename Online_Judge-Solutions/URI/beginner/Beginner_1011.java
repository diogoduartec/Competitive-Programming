package beginner;

import java.util.Scanner;

public class Beginner_1011 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double r = scan.nextDouble();
        System.out.printf("VOLUME = %.3f\n", 3.14159*(4.0/3)*r*r*r);
    }
}
