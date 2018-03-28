import java.util.Scanner;

public class Beginner_1018 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n100, n50, n20, n10, n5, n2, n1;
        int money  = scan.nextInt();
        int aux = money;
        n100=money/100;
        money%=100;

        n50=money/50;
        money%=50;

        n20=money/20;
        money%=20;

        n10=money/10;
        money%=10;

        n5=money/5;
        money%=5;

        n2=money/2;
        money%=2;

        n1 = money;

        System.out.println(aux);
        System.out.printf("%d nota(s) de R$ 100,00\n", n100);
        System.out.printf("%d nota(s) de R$ 50,00\n", n50);
        System.out.printf("%d nota(s) de R$ 20,00\n", n20);
        System.out.printf("%d nota(s) de R$ 10,00\n", n10);
        System.out.printf("%d nota(s) de R$ 5,00\n", n5);
        System.out.printf("%d nota(s) de R$ 2,00\n", n2);
        System.out.printf("%d nota(s) de R$ 1,00\n", n1);

    }
}
