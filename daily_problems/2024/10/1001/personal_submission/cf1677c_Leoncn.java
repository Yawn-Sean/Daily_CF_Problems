public class cf1677c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int[] g = new int[n];
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.ni() - 1;
        }
        for (int i = 0; i < n; i++) {
            p[g[i]] = sc.ni() - 1;
        }
        boolean[] vis = new boolean[n];
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if(vis[i]) continue;
            int cnt = 0;
            int tem = i;
            while (!vis[tem]){
                cnt ++;
                vis[tem] = true;
                tem = p[tem];
            }
            ans += cnt/2;
        }
        out.println(2* ans *(n-ans));
    }
}
