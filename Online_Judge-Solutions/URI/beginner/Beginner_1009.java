package beginner;
import java.io.IOException;
import java.util.Scanner;

public class Beginner_1009 {
    public static void main(String... args){
        Scanner scan = new Scanner(System.in);
        String name = scan.nextLine();
        double salary = scan.nextDouble();
        double sale = scan.nextDouble();
        System.out.printf("TOTAL = R$ %.2f\n", salary + sale*0.15);
    }
}
