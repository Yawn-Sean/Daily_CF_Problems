
public class cf1172b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int mod = 998244353;
        long[] cnt = new long[n];
        Arrays.fill(cnt, 1);
        long ans = n;
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            ans = ans * cnt[a] % mod * cnt[b] % mod;
            cnt[a] ++;
            cnt[b] ++;
        }
        out.println(ans);

    }

}
