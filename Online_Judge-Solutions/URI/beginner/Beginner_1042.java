package beginner;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Beginner_1042 {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        List<Integer> vet = new ArrayList<>();
        List<Integer> vetSorted = new ArrayList<>();
        
        for(int i=0; i<3; i++) {
            vet.add(scan.nextInt());
        }
        
        vetSorted.addAll(vet);
        
        Collections.sort(vetSorted);
        
        vetSorted.forEach(System.out::println);
        System.out.println();
        vet.forEach(System.out::println);
    }
}