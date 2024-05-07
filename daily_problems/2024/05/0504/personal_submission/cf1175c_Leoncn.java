public class cf1175c_Leoncn {
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
        int k = sc.ni();
        int[] g = sc.na(n);
        Arrays.sort(g);
        int ans = -1;
        int res = Integer.MAX_VALUE;
        for (int i = 0; i < n-k; i++) {
            int f = (g[i] + g[i+k])/2;
            int min = Math.max(f- g[i], g[i+k]-f);
            if(min<res){
                res = min;
                ans = f;
            }
        }
        out.println(ans);
    }

}
