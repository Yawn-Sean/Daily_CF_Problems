
public class cf1009e_Leoncn {
    public static void solve() {
        int mod = 998244353;
        int n = sc.ni();
        long[] g = sc.nal(n);
        long[] pow = new long[n+1];
        pow[0] = 1;
        for (int i = 0; i < n; i++) {
            pow[i+1] = pow[i] *2 %mod;
        }
        long ans = g[n-1];
        for (int i = 0; i < n-1; i++) {
            ans += g[i] * (pow[n - i - 1] +  pow[n - i - 2] * (n - i - 1) %mod ) % mod;
            ans %= mod;
        }
        out.println(ans);
    }
}
