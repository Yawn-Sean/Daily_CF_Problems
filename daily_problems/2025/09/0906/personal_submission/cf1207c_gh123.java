//https://codeforces.com/problemset/submission/1207/337085381
//每次都是状态转移方程最难想了。。。
import java.util.Arrays;
import java.util.Scanner;

public class C1207 {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int t=sc.nextInt();
        long inf=(long)1e15;
        while (t-->0) {
            int n=sc.nextInt();
            long a=sc.nextLong();
            long b=sc.nextLong();
            char[]cs=sc.next().toCharArray();
            if(n==2){
                System.out.println(2*a+3*b);
                continue;
            }
            long[][]dp=new long[n][2];
            for (long[] d : dp) {
                Arrays.fill(d, inf);   
            }
            dp[0][0]=2*b+a;
            dp[0][1]=3*b+2*a;
            for (int i = 1; i < dp.length; i++) {
                dp[i][1]=dp[i-1][1]+2*b+a;
                if(cs[i]=='0'){
                    dp[i][1]=Math.min(dp[i][1], Math.min(dp[i][1]+a+2*b, dp[i-1][0]+2*a+2*b));
                    dp[i][0]=Math.min(dp[i-1][1]+2*a+b, dp[i-1][0]+a+b);
                }
            }
            System.out.println(dp[n-1][0]);
        }
        sc.close();
    }
}
