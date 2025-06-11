
public class cf1017d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int q = sc.ni();
        int[] g = sc.na(n);
        int[] cnt = new int[1<<n];
        for (int i = 0; i < m; i++) {
            String s = sc.ns();
            int mask = 0;
            for (int j = 0; j < n; j++) {
                mask = mask * 2 + (s.charAt(j)-'0');
            }
            cnt[mask]++;
        }
        int[] dp= new int[1<<n];
        for (int i = 1; i < 1<<n; i++) {
            int x = i & -i;
            dp[i] = dp[i - x] + g[n - (32-Integer.numberOfLeadingZeros(x))];
        }
        int[][] ans = new int[101][1<<n];
        int tot = (1<<n) -1;
        for (int i = 0; i < 1<<n; i++) {
            for (int j = 0; j < 1<<n; j++) {
                if(dp[tot - (i^j)]<=100){
                    ans[dp[tot - (i^j)]][i] += cnt[j];
                }
            }
            for (int j = 0; j < 100; j++) {
                ans[j+1][i] += ans[j][i];
            }
        }


        while (q-->0){
            String t = sc.ns();
            int k = sc.ni();
            int a = 0;
            for (int i = 0; i < n; i++) {
                a = a *2 + (t.charAt(i)- '0');
            }
            out.println(ans[k][a]);

        }

    }

}
