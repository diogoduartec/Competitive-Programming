import java.util.*;
import java.lang.*;
import java.io.*;
public class Beginner_1002 {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(System.in);
        double R = scanner.nextDouble();
        double A = 3.14159*R*R;
        System.out.printf("A=%.4f\n", A);
    }
}