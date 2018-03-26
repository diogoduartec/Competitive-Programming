package beginner;
import java.io.*;
import java.util.*;
import java.lang.*;
import java.text.DateFormat;

public class Main {
    public static void main(String[] args) throws ParseException{
        Calendar c = Calendar.getInstance();
        Date data = c.getTime();
        DateFormat f = DateFormat.getDateInstance();

        Date data2 = f.parse("12/01/1995");
        System.out.println(data2);

        SimpleDateFormat sdf = new SimpleDateFormat("dd/MM/yyyy");
        System.out.println("Data formatada: "+sdf.format(data));

        //Converte Objetos
        System.out.println("Data convertida: " + sdf.parse("02/08/1970"));
    }
}
