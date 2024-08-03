public class cf1310a_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);

    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    public static void solve() {
        int n = sc.ni();
        int[][] g = new int[n][2];
        for (int i = 0; i < n; i++) {
            g[i][0] = sc.ni();
        }
        for (int i = 0; i < n; i++) {
            g[i][1] = sc.ni();
        }
        Arrays.sort(g,(a,b)->a[0]-b[0]);
        PriorityQueue<int[]> pq = new PriorityQueue<>((a,b)->b[1]-a[1]);
        int pre = -1;
        long ans = 0;
        for (int i = 0; i < n; i++) {
            if (pq.size() != 0) {
                if (pre != g[i][0]) {
                    while (pq.size() > 0 && pre < g[i][0]) {
                        int[] p = pq.poll();
                        ans += (long) (pre - p[0]) * p[1];
                        pre++;
                    }
                }
            }
            pre = g[i][0];
            pq.add(g[i]);
        }
        while (pq.size()>0){
            int[] p = pq.poll();
            ans += (long) (pre - p[0]) * p[1];
            pre++;
        }
        out.println(ans);
    }
}
