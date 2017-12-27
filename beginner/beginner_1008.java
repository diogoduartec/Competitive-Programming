package beginner;
import java.util.*;
import java.lang.*;
import java.io.*;
public class beginner_1008 {
    public static void main(String... args){
        Scanner scan = new Scanner(System.in);
        int number = scan.nextInt();
        double hour = scan.nextDouble();
        double moneyPerHour = scan.nextDouble();
        System.out.printf("NUMBER = %d\nSALARY = U$ %.2f\n", number, (hour * moneyPerHour));
    }
}
