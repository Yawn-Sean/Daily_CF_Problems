
public class cf489d_Leoncn {
    static ArrayList<Integer>[] g;
    static int n, m;
    public static void solve() {
        n = sc.ni();
        m = sc.ni();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int f = sc.ni() - 1;
            int to = sc.ni() - 1;
            g[f].add(to);
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int[] cnt = new int[n];
            dfs(i, cnt, 0);
            for (int j = 0; j < n; j++) {
                if(i!=j && cnt[j]>1){
                    ans += (long)(cnt[j]-1)*cnt[j]/2;
                }
            }
        }
        out.println(ans);

    }
    private static void dfs(int cur, int[] cnt, int level){
        for(int w: g[cur]){
            if(level+1<2){
                dfs(w, cnt, level+1);
            }else if(level+1==2){
                cnt[w]++;
            }
        }
    }

}
