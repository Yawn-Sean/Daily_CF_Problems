//https://codeforces.com/problemset/submission/1452/304969190
import java.util.Scanner;

public class D1452 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int mod=998244353;
        long a=0;
                long b=1;
        for (int i = 0; i < n; i++) {
            a+=b;
            if(a>=mod)a-=mod;
            long tem=a;
            a=b;
            b=tem;
        }
        long rev=(mod+1)/2;
        sc.close();
        for (int i = 0; i < n; i++) {
            a=1l*a*rev%mod;
        }
        System.out.println(a);
    }
}
