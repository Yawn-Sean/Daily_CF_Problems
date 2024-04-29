public class cf567e_Leoncn {
    static RealFastReader sc = new RealFastReader(System.in);
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) {
        int t = 1;
        while (t-->0){
            solve();
        }
        out.close();
    }

    static final long INF = (long) 1e12;
    private static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int s = sc.ni() - 1;
        int t = sc.ni() - 1;
        ArrayList<Long>[] path = new ArrayList[n];
        ArrayList<Long>[] revPath = new ArrayList[n];
        List<int[]> edges = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            path[i] = new ArrayList<>();
            revPath[i] = new ArrayList<>();
        }
        for (int i = 0; i < m; i++) {
            int u = sc.ni() - 1;
            int v = sc.ni() - 1;
            long w = sc.ni();
            path[u].add(w*n + v);
            revPath[v].add(w*n + u);
            edges.add(new int[]{u, v, (int)w});
        }
        long[] distS = new long[n];
        Arrays.fill(distS, INF);
        distS[s] = 0;
        PriorityQueue<Long> pq = new PriorityQueue<>();
        pq.add((long) s);
        while (!pq.isEmpty()) {
            long curr = pq.poll();
            int u = (int) (curr % n);
            long d = curr / n;
            if (distS[u] != d) continue;

            for (long msk : path[u]) {
                long w = msk / n;
                int v = (int)(msk % n);
                if (distS[v] > d + w) {
                    distS[v] = d + w;
                    pq.add(distS[v] * n + v);
                }
            }
        }
        long[] distT = new long[n];
        Arrays.fill(distT, INF);
        distT[t] = 0;
        pq.add((long) t);

        while (!pq.isEmpty()) {
            long curr = pq.poll();
            int u = (int) (curr % n);
            long d = curr / n;
            if (distT[u] != d) continue;

            for (long msk : revPath[u]) {
                long w = msk / n;
                int v = (int)(msk % n);
                if (distT[v] > d + w) {
                    distT[v] = d + w;
                    pq.add(distT[v] * n + v);
                }
            }
        }

        long lowerBound = (long)1e8; // 下限
        long upperBound = (long)1e9; // 上限

        long rnd =(long) (new Random().nextDouble()*(upperBound-lowerBound) + lowerBound);

        long[] dpS = new long[n];
        dpS[s] = 1;
        Integer[] vertices = new Integer[n];
        for (int i = 0; i < n; i++) vertices[i] = i;
        Arrays.sort(vertices, Comparator.comparingLong(x -> distS[x]));

        for (int u : vertices) {
            for (long msk : revPath[u]) {
                long w = msk / n;
                int v = (int)(msk % n);
                if (distS[u] == distS[v] + w) {
                    dpS[u] += dpS[v];
                    dpS[u] %= rnd;
                }
            }
        }

        long[] dpT = new long[n];
        dpT[t] = 1;

        // Sorting vertices by distT
        Arrays.sort(vertices, Comparator.comparingLong(x -> distT[x]));

        for (int u : vertices) {
            for (long msk : path[u]) {
                long w = msk / n;
                int v = (int)(msk % n);
                if (distT[u] == distT[v] + w) {
                    dpT[u] += dpT[v];
                    dpT[u] %= rnd;
                }
            }
        }
        long totDist = distS[t];
        long totMethod = dpS[t];
        List<String> outs = new ArrayList<>();
        for (int[] edge : edges) {
            int u = edge[0];
            int v = edge[1];
            long w = edge[2];
            if (distS[u] + distT[v] + w == totDist) {
                if ( dpS[u] * dpT[v] % rnd == totMethod) {
                    outs.add("YES");
                } else {
                    outs.add(w > 1 ? "CAN 1" : "NO");
                }
            } else if (distS[u] + distT[v] >= totDist - 1) {
                outs.add("NO");
            } else {
                outs.add("CAN " + (w - totDist + 1 + distS[u] + distT[v]));
            }
        }

        for (String d : outs) {
           out.println(d);
        }

    }
}
