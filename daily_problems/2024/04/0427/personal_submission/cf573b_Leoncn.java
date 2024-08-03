public class cf573b_Leoncn {
    
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
        int[] g = sc.na(n);
        int[] left = new int[n];
        left[0] = 1;
        for (int i = 1; i < n; i++) {
            left[i] = Math.min(g[i], left[i-1] + 1);
        }
        int r = 1;
        int ans = 1;
        for (int i = n-2; i >=0 ; i--) {
            r = Math.min(r + 1 , g[i]);
            ans = Math.max(Math.min(left[i], r), ans);
        }
        out.println(ans);
    }

    
}
