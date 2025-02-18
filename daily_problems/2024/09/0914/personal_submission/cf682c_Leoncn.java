
public class cf682c_Leoncn {
    static ArrayList<int[]>[] g;
    static int[] arr;
    static int[] cnt;
    static int n;
    static int ans;
    public static void solve() {
        n = sc.ni();
        arr = sc.na(n);
        ans = 0;
        g = new ArrayList[n];
        cnt = new int[n];
        for (int i = 0; i <n ; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 1; i < n; i++) {
            int a = i ;
            int p = sc.ni()-1;
            int w = sc.ni();
            g[a].add(new int[]{p, w});
            g[p].add(new int[]{a, w});
        }
        dfs1(0, -1);
        dfs(0, -1, 0);
        out.println(ans);
    }
    private static void dfs1(int c, int par){
        cnt[c] = 1;
        for(int[] next: g[c]){
            if(next[0] == par){
                continue;
            }
            dfs1(next[0], c);
            cnt[c] += cnt[next[0]];
        }
    }
    private static void dfs(int c, int par, long sum){
        for(int[] next: g[c]){
            if(next[0] == par){
                continue;
            }
            if(arr[next[0]]< sum + next[1]){
                ans+= cnt[next[0]];
            }else {
                dfs(next[0], c, Math.max(0, sum + next[1]));
            }

        }
    }
}
