
public class cf242d_Leoncn {
    static ArrayList<Integer>[] g;
    static int[] cnt;
    static List<Integer> ans;
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(b);
            g[b].add(a);
        }
        cnt = sc.na(n);
        ans = new ArrayList<>();
        for (int i = 0; i < n ; i++) {
            if(cnt[i] == 0){
                dfs(i);
            }
        }
        out.println(ans.size());
        for(int l:ans){
            out.print(l + " ");
        }
    }

    private static void dfs(int c){
        ans.add(c+1);
        cnt[c]--;
        for(int w: g[c]){
            if(--cnt[w] == 0){
                dfs(w);
            }
        }
    }

}
