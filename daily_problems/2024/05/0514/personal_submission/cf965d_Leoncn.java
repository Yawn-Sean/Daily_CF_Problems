import java.io.PrintWriter;

public class cf965d_Leoncn {
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
        int l = sc.ni();
        int[] g = sc.na(n-1);
        int cur = 0;

        for (int i = 0; i < l; i++) {
            cur += g[i];
        }
        int ans = cur;
        for (int i = l; i < n-1; i++) {
            cur -= g[i-l];
            cur += g[i];
            ans = Math.min(cur, ans);
        }
        out.println(ans);
    }
}
