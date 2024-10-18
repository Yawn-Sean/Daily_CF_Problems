
public class cf1833g_Leoncn {
    static ArrayList<int[]>[] g;
    static List<Integer> ans;
    public static void solve() {
        int n = sc.ni();
        g = new ArrayList[n];
        ans = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n-1; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            g[a].add(new int[]{b, i+1});
            g[b].add(new int[]{a, i+1});
        }
        if(n%3!=0){
            out.println(-1);
            return;
        }

        dfs(0, -1);
        if((ans.size() + 1)*3!=n){
            out.println(-1);
            return;
        }
        out.println(ans.size());
        for(int l: ans){
            out.print(l + " ");
        }
        out.println("");
    }
    private static int dfs(int c, int p){
        int res = 1;
        for(int[] w: g[c]){
            if(w[0] == p) continue;
            int r = dfs(w[0], c);
            res +=r;
            if(r%3==0){
                ans.add(w[1]);
            }
        }
        return res;
    }
}
