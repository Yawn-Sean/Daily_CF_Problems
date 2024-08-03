public class cf526c_Leoncn {
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
        int c = sc.ni();
        long h1 = sc.ni();
        long h2 = sc.ni();
        long w1 = sc.ni();
        long w2 = sc.ni();
        long ans = 0;
        for (int i = 0; i <= 1e5 ; i++) {
            if(w1*i>c) break;
            ans = Math.max(ans, h1*i + (c-w1*i)/w2 *h2);
        }
        for (int i = 0; i <= 1e5 ; i++) {
            if(w2*i>c) break;
            ans = Math.max(ans, h2*i + (c-w2*i)/w1*h1);
        }

        out.println(ans);
    }
}
