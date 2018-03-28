import java.util.Scanner;

public class Beginner_1038 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int code = scan.nextInt();
        int quant = scan.nextInt();
        switch (code){
            case 1:
                System.out.printf("Total: R$ %.2f\n", quant*4.00);
                break;
            case 2:
                System.out.printf("Total: R$ %.2f\n", quant*4.50);
                break;
            case 3:
                System.out.printf("Total: R$ %.2f\n", quant*5.00);
                break;
            case 4:
                System.out.printf("Total: R$ %.2f\n", quant*2.00);
                break;
            case 5:
                System.out.printf("Total: R$ %.2f\n", quant*1.50);
                break;
        }
    }
}
