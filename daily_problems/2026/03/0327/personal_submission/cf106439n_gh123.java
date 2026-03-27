import java.util.Scanner;

public class cf106439n {
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        int m=200005;
        int mod=(int)1e9+7;
        long[]pw2=new long[m];
        long[]dp=new long[m];
        pw2[0]=1;
        for (int i = 1; i < m; i++) {
            pw2[i]=(pw2[i-1]*2)%mod;
        }   
        dp[1]=1;
        for (int i = 2; i < m; i++) {
            long val1=dp[i-1];
            long val2=(2*dp[i-2])%mod;
            long val3=pw2[i-1];
            dp[i]=(val1+val2+val3)%mod;
        }
        int t=sc.nextInt();
        while (t-->0) {
            int n=sc.nextInt();
            System.out.println(dp[n]);
        }
        sc.close();
    }
}
