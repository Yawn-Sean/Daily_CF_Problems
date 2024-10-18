public class Main{
    private static void solve() throws IOException {
        n = sc.nextInt();
        m = sc.nextInt();
        g = new List[n+1];
        Arrays.setAll(g, e -> new ArrayList<>());
        int[] degree = new int[n + 1];
        for (int i = 0; i < m; i++) {
            int x = sc.nextInt(), y = sc.nextInt();
            if (x > y) {
                int tmp = x;
                x = y;
                y = tmp;
            }
            g[x].add(y);
            degree[x]++;
            degree[y]++;
        }
        int[] dp = new int[n + 1];
        Arrays.fill(dp, 1);
        for (int i = 1; i < n + 1; i++) {
            for (int j : g[i]) {
                dp[j] = Math.max(dp[j], dp[i] + 1);
            }
        }
        long ans = 0L;
        for (int i = 1; i < n + 1; i++) {
            ans = Math.max((long) dp[i] * degree[i], ans);
        }
        sc.println(ans);
    }
}
