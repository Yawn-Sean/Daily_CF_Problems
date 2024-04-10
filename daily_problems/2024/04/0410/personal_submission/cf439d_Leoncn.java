public class cf439d_Leoncn {
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
        int[] a = sc.na(n);
        int[] b = sc.na(m);
        Arrays.sort(a);
        Arrays.sort(b);
        int min = Math.min(n,m);
        long ans = 0;
        for (int i = 0; i < min; i++) {
            ans += Math.max(0, -a[i]+ b[m-1-i]);
        }
        out.println(ans);

    }

}
