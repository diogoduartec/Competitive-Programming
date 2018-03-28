import java.util.Scanner;

public class Beginner_1013 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int maiorAb = (a+b + Math.abs(a-b))/2;
        System.out.printf("%d eh o maior\n", (c+maiorAb + Math.abs(c-maiorAb))/2);
    }
}
