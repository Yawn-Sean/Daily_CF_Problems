public class cf739a_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int ans = n;
        for (int i = 0; i < m; i++) {
            int l = sc.ni();
            int r = sc.ni();
            ans = Math.min(ans, r-l+1);
        }
        out.println(ans);
        for (int i = 0; i < n; i++) {
            out.print(i%ans  + " ");
        }
    }
}
