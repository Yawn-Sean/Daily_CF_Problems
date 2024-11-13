//https://codeforces.com/problemset/submission/575/290165726
import java.util.Scanner;

public class D575 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        System.out.println(2000);
        for (int i = 1; i <=1000; i++) {
            System.out.println(i+" 1 "+i+" 2");
        }
        for (int i = 1000; i >=1; i--) {
            System.out.println(i+" "+1+" "+i+" 2");
        }
        sc.close();
    }
}
