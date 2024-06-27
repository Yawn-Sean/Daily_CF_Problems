//https://codeforces.com/problemset/submission/1085/267587575
import java.util.Scanner;
public class D1085 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int k=sc.nextInt();
        int[]a=new int[n];
        for (int i = 0; i < n-1; i++) {
            int x=sc.nextInt()-1;
            int y=sc.nextInt()-1;
            a[x]++;
            a[y]++;
        }
        double ans=0;
        for (int i : a) {
            if(i==1) ans++;
        }
        System.out.println(k/ans*2);
        sc.close();
    }
}
