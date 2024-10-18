public class cf1195d2_Leoncn {
    
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        int mod = 998244353;
        long ans = 0;
        long[] cnt = new long[11];
        for (int i = 0; i < n; i++) {
            String s = String.valueOf(g[i]);
            cnt[s.length()]++;
        }
        for (int i = 0; i < n; i++) {
            long a = g[i];
            long b = 0;
            long power = 1;
            for (int j = 1; j < cnt.length; j++) {
                    b = (b + a % 10 * power) % mod;
                    a /= 10;
                    ans += (a * 10 * power + b) * cnt[j] * 10 % mod;
                    ans += (a * 100 * power + b) * cnt[j] % mod;
                    ans %= mod;
                    power = power * 100 % mod;
            }
        }
        out.println(ans);
    }
}
