//https://codeforces.com/problemset/submission/877/318891697
import java.util.Scanner;

public class C877 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        System.out.println(n+n/2);   
        sc.close();
        for (int i = 2; i <=n; i+=2) {
            System.out.print(i+" ");
        }
        for (int i = 1; i <=n; i+=2) {
            System.out.print(i+" ");
        }
        for (int i = 2; i <=n; i+=2) {
            System.out.print(i+" ");
        }
    }
}
