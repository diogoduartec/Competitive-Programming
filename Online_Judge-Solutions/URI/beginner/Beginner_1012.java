import java.util.Scanner;

public class Beginner_1012 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        System.out.printf("TRIANGULO: %.3f\n", (a * c)/2);
        System.out.printf("CIRCULO: %.3f\n", 3.14159 * c * c);
        System.out.printf("TRAPEZIO: %.3f\n", (a+b) * c / 2);
        System.out.printf("QUADRADO: %.3f\n", b*b);
        System.out.printf("RETANGULO: %.3f\n", a * b);
    }
}
