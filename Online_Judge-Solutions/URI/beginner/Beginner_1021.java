import java.util.Scanner;

public class Beginner_1021 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int n100, n50, n20, n10, n5, n2;
        int c100, c50, c25, c10, c5, c1;
        double moneyDouble = scan.nextDouble();
        int money  = (int) moneyDouble;
        double coinsDouble = moneyDouble - money;
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

        c100=money;



        int coins = (int) (coinsDouble*100);
        c50 = coins/50;
        coins%=50;

        c25 = coins/25;
        coins%=25;

        c10 = coins/10;
        coins%=10;

        c5 = coins/5;
        coins%=5;

        c1 = coins;

        System.out.println("NOTAS:");
        System.out.printf("%d nota(s) de R$ 100.00\n", n100);
        System.out.printf("%d nota(s) de R$ 50.00\n", n50);
        System.out.printf("%d nota(s) de R$ 20.00\n", n20);
        System.out.printf("%d nota(s) de R$ 10.00\n", n10);
        System.out.printf("%d nota(s) de R$ 5.00\n", n5);
        System.out.printf("%d nota(s) de R$ 2.00\n", n2);

        System.out.println("MOEDAS:");
        System.out.printf("%d moeda(s) de R$ 1.00\n", c100);
        System.out.printf("%d moeda(s) de R$ 0.50\n", c50);
        System.out.printf("%d moeda(s) de R$ 0.25\n", c25);
        System.out.printf("%d moeda(s) de R$ 0.10\n", c10);
        System.out.printf("%d moeda(s) de R$ 0.05\n", c5);
        System.out.printf("%d moeda(s) de R$ 0.01\n", c1);

    }
}
