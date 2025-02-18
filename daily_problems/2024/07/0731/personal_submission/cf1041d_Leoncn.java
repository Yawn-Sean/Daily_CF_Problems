
public class cf1041d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int h = sc.ni();
        int[][] g = sc.nmi(n,2);
        int l = 0;
        int c = g[0][1] - g[0][0];
        int ans = h + g[0][1] - g[0][0];
        for (int i = 1; i < n; i++) {
            c += g[i][1] - g[i][0];
            while (g[i][1] - g[l][0]>= h + c){
                c -= g[l][1] - g[l][0];
                l++;
            }
            ans = Math.max(h + c, ans);

        }
        out.println(ans);
    }
}
