public class cf1525e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int mod = 998244353;
        int[][] dis = sc.nmi(n,m);
        //求 1/(n!) mod
        long v = 1;
        for (int i = 1; i <= n; i++) {
             v = v *i;
             v %= mod;
        }
        v = pow(v, mod - 2, mod);

        long ans = 0;
        for (int i = 0; i < m; i++) {
            int[] cnt = new int[n];
            for (int j = 0; j < n; j++) {
                if(dis[j][i]>=2){
                    cnt[dis[j][i] - 2] ++;
                }
            }
            long s = 0;
            long res = 1;
            for (int j = n-1; j >=0 ; j--) {
                s += cnt[j];
                res = res * s%mod;
                s--;
            }
            ans = ((ans + 1 - res* v)%mod + mod)%mod;
        }
        out.println(ans);
    }
    static long pow(long x, long k, long p) {
        long res = 1;
        while (k != 0) {
            if ((k & 1) != 0) res = res * x % p;
            x = x * x % p;
            k >>= 1;
        }
        return res;
    }
}
