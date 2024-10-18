
public class cf597c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int k = sc.ni();
        int[] g = sc.na(n);
        Fenwick f = new Fenwick(n+2);
        long[] dp = new long[n];
        Arrays.fill(dp, 1);
        for (int i = 0; i < k; i++) {
            f = new Fenwick(n+2);
            for (int j = 0; j < n; j++) {
                f.add(g[j], dp[j]);
                dp[j] = f.pre(g[j]-1);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += dp[i];
        }
        out.println(ans);
    }
}
