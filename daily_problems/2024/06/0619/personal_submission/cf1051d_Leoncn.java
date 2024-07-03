public class cf1051d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int mod = 998244353;
        if(k==1){
            out.print(2);
            return;
        }
        long[][][] dp = new long[n+1][k+1][4];

        dp[1][1][0] = 1;
        dp[1][2][1] = 1;
        dp[1][2][2] = 1;
        dp[1][1][3] = 1;
        for (int i = 2; i <=n ; i++) {
            for (int j = 1; j <=Math.min(2*i, k); j++) {
                dp[i][j][0] = (dp[i-1][j][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j-1][3])%mod;
                dp[i][j][1] = (dp[i-1][j-1][0] + dp[i-1][j][1] + (j>=2?dp[i-1][j-2][2]:0)+ dp[i-1][j-1][3])%mod;
                dp[i][j][2] = (dp[i-1][j-1][0] + (j>=2?dp[i-1][j-2][1]:0) + dp[i-1][j][2] + dp[i-1][j-1][3])%mod;
                dp[i][j][3] = (dp[i-1][j-1][0] + dp[i-1][j][1] + dp[i-1][j][2] + dp[i-1][j][3])%mod;
            }
        }
        out.print((dp[n][k][0] + dp[n][k][1]+dp[n][k][2]+dp[n][k][3])%mod);
    }
}
