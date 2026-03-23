//https://codeforces.com/problemset/submission/1368/367840810
import java.util.Scanner;

public class cf1368c {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(3*n+4);
        for (int i = -1; i < n; i++) {
            System.out.println(i+" "+i);
            System.out.println(i+" "+(i+1));
            System.out.println((i+1)+" "+i);
        }   
        System.out.println(n+" "+n);
        sc.close();
    }
}
