public class cf1151d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[][] g = sc.nmi(n,2);
        Arrays.sort(g, (a,b)->a[1]-b[1] - (a[0]-b[0]));
        long ans = 0;
        for (int i = 0; i < n; i++) {
            ans += (long)(g[i][0])*i + (long)g[i][1] *(n-1-i);
        }
        out.println(ans);
    }
}
