public class cf1282b2_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int p = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        Arrays.sort(g);
        int[] dp = new int[n+1];
        for (int i = 0; i < k-1; i++) {
            dp[i+1] = g[i]+ dp[i];
        }
        for (int i = k-1; i <n ; i++) {
            dp[i+1] = g[i] + dp[i-k+1];
        }
        for (int i = n; i >=0 ; i--) {
            if(dp[i]<=p){
                out.println(i);
                return;
            }
        }

    }    
}
