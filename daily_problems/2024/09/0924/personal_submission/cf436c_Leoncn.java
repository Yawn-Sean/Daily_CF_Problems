
public class cf436c_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        int w = sc.ni();
        int[] par = new int[k+1];
        for (int i = 0; i <=k; i++) {
            par[i] = i;
        }
        char[][][] g = new char[k][n][m];
        for (int i = 0; i < k; i++) {
            g[i] = sc.nm(n, m);
        }
        int[][] dis = new int[k+1][k+1];
        for (int i = 0; i < k; i++) {
            dis[0][i+1] = n*m;
            for (int j = 0; j < i; j++) {
                int cnt = 0;
                for (int l = 0; l < n; l++) {
                    for (int h = 0; h <m; h++) {
                        if(g[i][l][h] != g[j][l][h]){
                            cnt++;
                        }
                    }
                }
                dis[j+1][i+1] = cnt * w;
            }
        }
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->a[2]-b[2]);
        for (int i = 0; i <=k; i++) {
            for (int j = 0; j <i ; j++) {
                pq.add(new int[]{i, j, dis[j][i]});
            }
        }
        int ans = 0;
        ArrayList<Integer>[] arr = new ArrayList[k+1];
        for (int i = 0; i <=k ; i++) {
            arr[i] = new ArrayList<>();
        }
        while (pq.size()>0){
            int[] p = pq.poll();
            int p1 = root(p[0], par);
            int p2 = root(p[1], par);
            if(p1 == p2){
                continue;
            }
            ans += p[2];
            par[p1] = p2;
            arr[p[0]].add(p[1]);
            arr[p[1]].add(p[0]);
        }
        out.println(ans);
        Deque<Integer> dq = new ArrayDeque<>();
        dq.add(0);
        boolean[] vis = new boolean[k+1];
        vis[0] =true;
        while (dq.size()>0){
            int p = dq.poll();
            for(int h: arr[p]){
                if(vis[h]) continue;
                vis[h] = true;
                dq.add(h);
                out.println(h +   " " + p);
            }
        }
    }
}
