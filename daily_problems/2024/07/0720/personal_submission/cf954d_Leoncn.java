public class cf954d_Leoncn {
    static ArrayList<Integer>[] g;
    static int n;
    public static void solve() {
        n = sc.ni();
        int m = sc.ni();
        int s = sc.ni() - 1;
        int t = sc.ni() - 1;
        g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        boolean[][] vis = new boolean[n][n];
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            vis[a][b] = true;
            vis[b][a] = true;
            g[a].add(b);
            g[b].add(a);
        }
        int[] fr = minLen(s);
        int[] to = minLen(t);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j <n ; j++) {
                if(vis[i][j]) continue;
                if(Math.min(fr[i] + to[j] + 1,fr[j] + to[i] + 1) >= fr[t]){
                    ans++;
                }
            }
        }
        out.println(ans);
    }
    private static int[] minLen(int s){
        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(s);
        int[] res = new int[n];
        Arrays.fill(res, -1);
        res[s] = 0;
        while (dq.size()>0){
            int p = dq.poll();
            for(int c: g[p]){
                if(res[c] == -1){
                    res[c] = res[p] + 1;
                    dq.add(c);
                }
            }
        }
        return res;
    }
}
