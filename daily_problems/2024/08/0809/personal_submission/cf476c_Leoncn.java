
public class cf476c_Leoncn {
    public static void solve() {
        long a = sc.nl(), b = sc.nl();
        long mod = (long)1e9 + 7;
        long ans = ((a * (a + 1) / 2 % mod) * b % mod + a) % mod * ( b * (b - 1) / 2 % mod) % mod;
        out.println(ans);
    }
}
