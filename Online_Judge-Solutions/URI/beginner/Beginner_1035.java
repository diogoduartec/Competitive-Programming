import java.util.Scanner;

public class Beginner_1035 {
    public static void main(String... args){
        Scanner scan = new Scanner(System.in);
        int a = scan.nextInt();
        int b = scan.nextInt();
        int c = scan.nextInt();
        int d = scan.nextInt();
        if(b>c && d>a && (c+d)>(a+b) && c>0 && d>0 && a%2==0 && a>1)
            System.out.println("Valores aceitos");
        else System.out.println("Valores nao aceitos");
    }
}
