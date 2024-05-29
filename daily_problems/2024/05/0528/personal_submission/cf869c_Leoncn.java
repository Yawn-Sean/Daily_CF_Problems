
public class cf869c_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    static int mod = 998244353;

    static Combitation combitation = new Combitation(5001,mod);
    public static void solve() {
        int a = sc.ni();
        int b = sc.ni();
        int c = sc.ni();

        long ans = cal(a,b) * cal(b,c) % mod * cal(a,c)%mod;
        out.println(ans);
    }
    private static long cal (int a, int b){
        int min = Math.min(a, b);
        long s = 1;
        long res = 1;
        for (int i = 1; i <=min; i++) {
            s = s*i%mod;
            res = (res + combitation.comb(a,i) * combitation.comb(b,i) % mod * s % mod)%mod;
        }
        return res;
    }
    public static class Combitation {

        static long[] fac;
        static long[] facR;
        static int mod;
        public Combitation(Integer max, Integer m){
            mod = m;
            fac = fac(max, mod);
            facR = facR(max, mod);
        }
        private static long[] pow(long p, long w, int mod) {
            long[] res = new long[(int)w];
            long r = 1;
            for (int i = 0; i < w; i++) {
                res[i] = r;
                r = r*p%mod;
            }
            return res;
        }


        public long comb(int a, int b) {
            if (a < b) return 0;
            return combine(a, b, mod);
        }
        //递推求阶乘
        static long[] fac(int n, long p) {
            long[] f = new long[n + 1];
            f[0] = f[1] = 1;
            for (int i = 2; i <= n; i++) {
                f[i] = f[i - 1] * i % p;
            }
            return f;
        }

        //facR
        static long[] facR(int n, long p) {
            long[] fr = new long[n + 1];
            fr[n] = pow(fac[n], p - 2, p) ;
            for (int i = n-1; i>=0 ; i--) {
                fr[i] = fr[i + 1] * (i+1) % p;
            }
            return fr;
        }

        //快速幂 x^k mod p
        static long pow(long x, long k, long p) {
            long res = 1;
            while (k != 0) {
                if ((k & 1) != 0) res = res * x % p;
                x = x * x % p;
                k >>= 1;
            }
            return res;
        }


        //公式法求组合数 O(NlogP)  结合逆元  求  C(a,b) mod p      a!/(b! (a-b)!)   1≤b≤a≤10^5
        static long combine(int a, int b, int p) {
            //先预处理出阶乘   然后 每次 常数时间求解
            return (fac[a] * facR[b] % p) * facR[a - b] % p;
        }


    }    
}
