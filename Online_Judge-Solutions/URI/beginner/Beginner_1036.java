import java.util.Scanner;

public class Beginner_1036 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        double a = scan.nextDouble();
        double b = scan.nextDouble();
        double c = scan.nextDouble();
        float delta = (float)((Math.pow(b,2))-(4*a*c));
        if(delta<0 || a==0)
            System.out.println("Impossivel calcular");
        else{
            float R1 =(float) ((-b) + (Math.sqrt(delta)));
            float R2 =(float) ((-b) - (Math.sqrt(delta)));
            R1/=2*a;
            R2/=2*a;
            System.out.printf("R1 = %.5f\n", R1);
            System.out.printf("R2 = %.5f\n", R2);
        }
    }
}
