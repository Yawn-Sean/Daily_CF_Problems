    public static void solve() {
        int n = sc.ni();
        int mod = sc.ni();
        long[] dp = new long[n+1];
        dp[1] = 1;
        long sum = 1;
        for (int i = 2; i <=n; i++) {
            int s = (int)Math.sqrt(i);
            long f = 0;
            for (int j = 1; j <=s ; j++) {
                int p = i/j;
                f = (f + dp[p])%mod ;
                f =  (f + dp[j]*(p - i/(j+1))) %mod;
                if(p == j){
                    f = (f- dp[j])%mod;
                }
            }
            dp[i] = f;
            dp[i] = (dp[i] + sum)%mod;
            sum = (sum +  dp[i])%mod;
        }
        out.println((dp[n]%mod + mod)%mod);
    }
