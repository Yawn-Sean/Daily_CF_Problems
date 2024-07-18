
public class cf1594d_Leoncn {
    static int[] st;
    static ArrayList<Integer>[] g;
    static int cnt;
    static int n;
    public static void solve() {
        n = sc.ni();
        int m = sc.ni();
        DJSet djSet = new DJSet(2*n+1);
        st = new int[2*n+1];
        g = new ArrayList[2*n+1];

        for (int i = 0; i < 2*n+1; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni(), b = sc.ni();
            String s = sc.ns();
            if(s.equals("imposter")){
                g[a].add(b+n);
                g[b+n].add(a);
                g[b].add(a+n);
                g[a+n].add(b);
                djSet.unite(a,b+n);
                djSet.unite(b,a+n);
            }else {
                g[a].add(b);
                g[b].add(a);
                g[a+n].add(b+n);
                g[b+n].add(a+n);
                djSet.unite(a,b);
                djSet.unite(a+n, b+n);
            }
        }
        for (int i = 1; i <=n ; i++) {
            if(djSet.root(i) == djSet.root(i+n)){
                out.println(-1);
                return;
            }
        }
        int ans = 0;
        for (int i = 1; i <=n ; i++) {
            cnt = 0;
            if(st[i] == 0 && st[i+n] == 0){
                int res = dfs(i, -1);
                ans += Math.max(cnt, res - cnt);
            }
        }
        out.println(ans);

    }
    private static int dfs(int c, int p){
        if(st[c] == 1) return 0;
        st[c] = 1;
        if(c>n){
            cnt++;
        }
        int res = 1;
        for(int w: g[c]){
            if(w == p) continue;
            res += dfs(w, c);
        }
        return res;
    }
}
