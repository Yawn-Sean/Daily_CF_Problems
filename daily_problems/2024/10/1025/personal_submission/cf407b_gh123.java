//https://codeforces.com/problemset/submission/407/287845193
import java.util.Scanner;
//这次是跟着题解写出来的。。
public class B407 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int n=sc.nextInt();
        int mod=(int)1e9+7;
        int[]next=new int[n];
        for (int i = 0; i < n; i++) {
            next[i]=sc.nextInt()-1;
        }
        sc.close();
        int[]dp=new int[n+1];
        for (int i = 0; i < n; i++) {
            dp[i+1]=2*dp[i];
            dp[i+1]%=mod;
            dp[i+1]-=dp[next[i]];
            if(dp[i+1]<0)dp[i+1]+=mod;
            dp[i+1]+=2;
            dp[i+1]%=mod;
        }
        System.out.println(dp[n]);
    }
}
