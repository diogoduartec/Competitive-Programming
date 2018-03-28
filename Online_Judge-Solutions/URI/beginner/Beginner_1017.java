import java.util.Scanner;

public class Beginner_1017 {
    public static void main(String... args){
        Scanner scan = new Scanner(System.in);
        int time = scan.nextInt();
        int speed = scan.nextInt();
        System.out.printf("%.3f\n", (time*speed)/12.0);
    }
}
