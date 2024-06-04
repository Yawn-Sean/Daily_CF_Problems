public class cf1954d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }
    private static final int MOD = 998244353;
    public static void solve() {
        int n = sc.ni();
        int[] g = sc.na(n);
        Arrays.sort(g);
        int max = 5001;
        long[] sum  = new long[max];
        sum[0] = 1;

        int cur = 0;
        long ans = 0;
        for(int a: g){
            for (int i = cur; i >=0 ; i--) {
                if(sum[i]>0){
                    ans = (sum[i] * Math.max((i + a + 1)/2, a) + ans)%MOD;
                    sum[i+a] = (sum[i+a] + sum[i]) % MOD;
                }
            }
            cur += a;
        }
        out.println(ans);


    }

}
