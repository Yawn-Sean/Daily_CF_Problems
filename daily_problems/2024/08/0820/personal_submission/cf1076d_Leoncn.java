
public class cf1076d_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        ArrayList<int[]>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) {
            g[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int a = sc.ni() - 1;
            int b = sc.ni() - 1;
            int w = sc.ni();
            g[a].add(new int[]{b, w, i});
            g[b].add(new int[]{a, w, i});
        }
        long[] dis = new long[n];
        int[] par = new int[n];
        Arrays.fill(dis, Long.MAX_VALUE/10);
        dis[0] = 0;
        PriorityQueue<Integer> dq = new PriorityQueue<>((a,b)->Long.compare(dis[a],dis[b]));
        dq.add(0);
        while (dq.size()>0){
            int p = dq.poll();
            for(int[] w: g[p]){
                if(w[1] + dis[p] < dis[w[0]]){
                    par[w[0]] = w[2];
                    dis[w[0]] = w[1] + dis[p];
                    dq.add(w[0]);
                }
            }
        }
        List<Integer> list = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            list.add(i);
        }
        list.sort((a,b)->Long.compare(dis[a],dis[b]));
        int ans = Math.min(k, n-1);
        out.println(ans);
        for (int i = 0; i < ans; i++) {
            out.print(par[list.get(i)]+1 + " ");
        }
    }

}
