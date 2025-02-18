
public class cf1131d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        DJSet dj = new DJSet(n+m);
        char[][] arr = new char[n][m];
        List<Integer>[] g = new ArrayList[n+m];
        for (int i = 0; i < g.length; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < n; i++) {
            char[] cs = sc.ns().toCharArray();
            arr[i] = cs;
            for (int j = 0; j < m; j++) {
                if(cs[j] == '='){
                    dj.unite(i, j+n);
                }
            }
        }
        int[] cnt = new int[n+m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(arr[i][j] == '=') continue;
                int r1 = dj.root(i);
                int r2 = dj.root(j+n);
                if(arr[i][j] == '>'){
                    g[r1].add(r2);
                    cnt[r2]++;
                }else if(arr[i][j] == '<'){
                    g[r2].add(r1);
                    cnt[r1]++;
                }
            }
        }
        int[] ans = new int[n+m];
        Arrays.fill(ans, -1);
        Deque<Integer> dq = new ArrayDeque<>();
        boolean[] vis = new boolean[n+m];
        for (int i = 0; i < n+m; i++) {
            int r = dj.root(i);
            if(!vis[r] && cnt[r] == 0){
                dq.add(r);
                vis[r] = true;
            }
        }
        int st = n+m;
        while (dq.size()>0){
            int s = dq.size();
            while (s-->0){
                int p = dq.poll();
                ans[p] = st;
                for(int w : g[p]){
                    if(--cnt[w] == 0){
                        dq.add(w);
                    }
                }
            }
            st--;
        }
        for (int i = 0; i < n+m; i++) {
            if(ans[i] != -1) continue;
            int r = dj.root(i);
            if(ans[r] == -1){
                out.println("No");
                return;
            }
            ans[i] = ans[r];
        }
        out.println("Yes");
        for (int i = 0; i < n; i++) {
            out.print(ans[i] -st + " ");
        }
        out.println(" ");
        for (int i = n; i <n+m ; i++) {
            out.print(ans[i]-st  + " ");
        }

    }
    public static class DJSet {
        public int[] upper;

        public DJSet(int n) {
            upper = new int[n];
            Arrays.fill(upper, -1);
        }

        public int root(int x) {
            return upper[x] < 0 ? x : (upper[x] = root(upper[x]));
        }

        public boolean equiv(int x, int y) {
            return root(x) == root(y);
        }

        public boolean unite(int x, int y) {
            x = root(x);
            y = root(y);
            if (x != y) {
                if (upper[y] < upper[x]) {
                    int d = x;
                    x = y;
                    y = d;
                }
                upper[x] += upper[y];
                upper[y] = x;
            }
            return x == y;
        }

        public int count() {
            int ct = 0;
            for (int u : upper) if (u < 0) ct++;
            return ct;
        }

        public int[][] toBucket() {
            int n = upper.length;
            int[][] ret = new int[n][];
            int[] rp = new int[n];
            for (int i = 0; i < n; i++) if (upper[i] < 0) ret[i] = new int[-upper[i]];
            for (int i = 0; i < n; i++) {
                int r = root(i);
                ret[r][rp[r]++] = i;
            }
            return ret;
        }
    }
}
