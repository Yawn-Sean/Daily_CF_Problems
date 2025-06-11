
public class cf615b_Leoncn {
    static List<Integer>[] g;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        g = new ArrayList[n];
        int[] cnt = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            if(a>b){
                int tem = b;
                b = a;
                a = tem;
            }
            g[b].add(a);
            cnt[a]++;
            cnt[b]++;
        }
        long[] dp = new long[n];
        Arrays.fill(dp,1);
        long ans = dp[0] * cnt[0];
        for (int i = 1; i < n; i++) {
            for(int w:g[i]){
                dp[i] = Math.max(dp[i], dp[w] + 1);
            }
            ans = Math.max(ans, dp[i] * cnt[i]);
        }
        out.println(ans);

    }
}
