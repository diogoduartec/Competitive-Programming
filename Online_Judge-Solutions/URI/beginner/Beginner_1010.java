package beginner;

import java.util.Scanner;

public class Beginner_1010 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int c1 = scan.nextInt();
        int u1 = scan.nextInt();
        double p1 = scan.nextDouble();
        int c2 = scan.nextInt();
        int u2 = scan.nextInt();
        double p2 = scan.nextDouble();
        System.out.printf("VALOR A PAGAR: R$ %.2f\n", u1*p1 + u2*p2);
    }
}
