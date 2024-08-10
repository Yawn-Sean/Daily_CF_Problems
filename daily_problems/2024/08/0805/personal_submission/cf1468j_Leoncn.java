
public class cf1468j_Leoncn {
    public static void solve() {
        int n = sc.ni();
        int m = sc.ni();
        int k = sc.ni();
        PriorityQueue<Data> pq = new PriorityQueue<>(Comparator.comparingInt(l -> l.weight));
        for (int i = 0; i < m; i++) {
            int x = sc.ni();
            int y = sc.ni();
            int weight = sc.ni();
            pq.add(new Data(x, y, weight));
        }

        DSU dsu = new DSU(n + 1);
        long result = Long.MAX_VALUE;
        long cost = 0;
        while (!pq.isEmpty()) {
            Data top = pq.poll();
            if (dsu.find(top.x) != dsu.find(top.y)) {
                cost += Math.max(0, top.weight - k);
            }
            int size = dsu.merge(top.x, top.y);
            if (size == n) {
                if (top.weight < k) {
                    result = Math.min(result, k - top.weight);
                } else {
                    result = Math.min(result, Math.max(cost, top.weight - k));
                    break;
                }
            }
        }
        out.println(result);
    }
    static class DSU {
        int n;
        int[] parent;
        int[] size;

        DSU(int n) {
            this.n = n;
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        int find(int x) {
            int px = parent[x];
            if (x == px) {
                return px;
            }
            parent[x] = find(px);
            return parent[x];
        }

        int merge(int x, int y) {
            int px = find(x);
            int py = find(y);
            if (px == py) {
                return size[px];
            }
            size[px] += size[py];
            parent[py] = px;
            return size[px];
        }

    }

    static class Data {
        int x;
        int y;
        int weight;

        public Data(int x, int y, int weight) {
            this.x = x;
            this.y = y;
            this.weight = weight;
        }

    }
}
