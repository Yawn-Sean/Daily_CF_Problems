//https://codeforces.com/problemset/submission/739/268558268
import java.util.Scanner;

public class A739 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int m=sc.nextInt();
        int min=Integer.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            int l=sc.nextInt();
            int r=sc.nextInt();
            min=Math.min(min, r-l+1);
        }
        System.out.println(min);
        for (int i = 0; i < n; i++) {
            System.out.println(i%min+" ");
        }
        sc.close();
    }
}
