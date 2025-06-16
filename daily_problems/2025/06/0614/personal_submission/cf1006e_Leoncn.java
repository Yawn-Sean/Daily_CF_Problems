
public class cf1006e_Leoncn {
    static int[] cnt;
    static int[] loc;
    static List<Integer>[] g;
    static List<Integer> ans;
    public static void solve() {
        int n = sc.ni();
        int q = sc.ni();
        g = new ArrayList[n];
        cnt = new int[n];
        loc = new int[n];
        ans = new ArrayList<>();
        for (int i = 0; i <n ; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int c = sc.ni() - 1;
            g[c].add(i+1);
        }
        dfs1(0);
        for (int i = 0; i < q; i++) {
            int u = sc.ni() - 1;
            int k = sc.ni();
            int res = -1;
            if(k <= cnt[u]){
                res = ans.get(loc[u] + k - 1) + 1;
            }
            out.println(res);
        }
    }

    private static void dfs1(int c){
        loc[c] = ans.size();
        cnt[c]++;
        ans.add(c);
        for(int next : g[c]){
            dfs1(next);
            cnt[c] += cnt[next];
        }
    }
}
