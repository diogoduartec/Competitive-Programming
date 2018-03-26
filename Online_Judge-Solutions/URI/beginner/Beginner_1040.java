package beginner;

import java.util.Scanner;

public class Beginner_1040 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        float n1 = scan.nextFloat();
        float n2 = scan.nextFloat();
        float n3 = scan.nextFloat();
        float n4 = scan.nextFloat();
        float average = (n1*2 + n2*3 + 4*n3 + n4)/10;
        System.out.printf("Media: %.1f\n", average);
        if(average>=7.0)
            System.out.println("Aluno aprovado.");
        else if(average<5.0)
            System.out.println("Aluno reprovado.");
        else{
            System.out.println("Aluno em exame.");
            float exam = scan.nextFloat();
            System.out.printf("Nota do exame: %.1f\n", exam);
            if((average+exam)/2>=5.0)
                System.out.println("Aluno aprovado.");
            else System.out.println("Aluno reprovado.");
            System.out.printf("Media final: %.1f\n", (average+exam)/2);
        }

    }
}
