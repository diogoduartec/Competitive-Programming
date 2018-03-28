import java.util.Scanner;

public class Beginner_1020 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int age = scan.nextInt();
        int years = age/365;
        age%=365;
        int months = age/30;
        age%=30;
        int days = age;

        System.out.printf("%d ano(s)\n", years);
        System.out.printf("%d mes(es)\n", months);
        System.out.printf("%d dia(s)\n", days);
    }
}
