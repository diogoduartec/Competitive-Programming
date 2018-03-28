import java.util.Scanner;

public class Beginner_1014 {
    public static void main(String... args){
        Scanner scan = new Scanner(System.in);
        int distance = scan.nextInt();
        float spendFuel = scan.nextFloat();
        System.out.printf("%.3f km/l\n", distance/spendFuel);
    }
}
