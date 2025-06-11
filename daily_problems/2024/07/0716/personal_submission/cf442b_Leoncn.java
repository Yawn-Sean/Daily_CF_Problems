
public class cf442b_Leoncn {
    public static void solve() {
        int n = sc.ni();
        Double[] g = new Double[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nd();
        }
        Arrays.sort(g, (a,b)->Double.compare(b,a));
        double p0 = 1, p1 = 0;
        double ans = 0;
        for (int i = 0; i < n; i++) {
            p1 = p1 * (1 - g[i]) + p0 * g[i];
            p0 *= 1 - g[i];
            ans = Math.max(ans, p1);
        }
        out.println(ans);
    }

}
