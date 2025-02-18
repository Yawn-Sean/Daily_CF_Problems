//https://codeforces.com/problemset/submission/476/275324505
import java.util.Scanner;

public class C476 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int mod=(int)1e9+7;
        long a=sc.nextLong(),b=sc.nextLong();
        long ans=0;
        for (int i = 1; i <=a; i++) {
            long c=(i*b+1)%mod;
            long d=(b*(b-1)/2)%mod;
            ans=(ans+c*d)%mod;
        }
        System.out.println(ans);
        sc.close();
    }
}
