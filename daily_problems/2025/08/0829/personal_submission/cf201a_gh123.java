//https://codeforces.com/problemset/submission/201/336085717
import java.util.Scanner;
public class A201 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int x=sc.nextInt();
        int n=1;
        while ((n*n+1)/2<x) {
            n+=2;
        }
        System.out.println(x==3?5:n);
        sc.close();
    }
}
