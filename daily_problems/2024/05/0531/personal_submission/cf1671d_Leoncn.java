
public class cf1671d_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = sc.ni();
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int x = sc.ni();
        int[] g = sc.na(n);
        long ans = 0;
        int f1 = Integer.MAX_VALUE, f2 = Integer.MAX_VALUE;
        for (int i = 0; i < n-1; i++) {
            ans += Math.abs(g[i+1] - g[i]);
        }
        for (int i = 0; i < n-1; i++) {
           f1 = Math.min((Math.min(g[i], g[i+1]) - 1)*2 ,f1);
           f2 = Math.min((x - Math.max(g[i], g[i+1]) )*2 ,f2);

        }
        f1 = Math.min(Math.min(g[0], g[n-1]) - 1, f1);
        f2 = Math.min(x - Math.max(g[0], g[n-1]) ,f2);
        f2 = Math.max(0, f2);
        out.println(ans + f1 + f2);
    }

}
