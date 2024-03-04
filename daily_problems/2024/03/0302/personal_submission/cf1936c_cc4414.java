import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(in.nextInt(), in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            for (int t = 0; t < testNumber; t++) {
                int n = in.nextInt();
                int m = in.nextInt();
                long[] c = new long[n];
                for (int i = 0; i < c.length; i++) {
                    c[i] = in.nextLong();
                }
                long[][] a = new long[n][m];
                for (int i = 0; i < n; i++) {
                    for (int j = 0; j < m; j++) {
                        a[i][j] = in.nextLong();
                    }
                }
                out.println(new Solution().solve(c, a));
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}

class Solution {
    public long solve(long[] c, long[][] a) {
        int n = a.length;
        int m = a[0].length;
        Map<Integer, Long>[] graph = buildGraph(c, a);
        return dijk(graph, n * m)[n * m + n - 1];
    }

    public long[] dijk(Map<Integer, Long>[] graph, int src) {
        int n = graph.length;
        PriorityQueue<Pair<Integer, Long>> queue = new PriorityQueue<>(Comparator.comparing(o -> o.value));
        long[] dis = new long[n];
        Arrays.fill(dis, Long.MAX_VALUE / 2);
        boolean[] vis = new boolean[n];
        queue.add(new Pair<>(src, 0L));
        while (!queue.isEmpty()) {
            Pair<Integer, Long> remove = queue.remove();
            if (vis[remove.key]) {
                continue;
            }
            dis[remove.key] = remove.value;
            vis[remove.key] = true;
            for (Map.Entry<Integer, Long> entry : graph[remove.key].entrySet()) {
                Integer key = entry.getKey();
                Long value = entry.getValue();
                queue.add(new Pair<>(key, remove.value + value));
            }
        }
        return dis;
    }

    public Map<Integer, Long>[] buildGraph(long[] c, long[][] a) {
        int n = a.length;
        int m = a[0].length;
        int s = n * m;
        Map<Integer, Long>[] maps = new Map[s + n];
        for (int i = 0; i < maps.length; i++) {
            maps[i] = new HashMap<>();
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                maps[s + i].put(i * m + j, 0L);
                maps[i * m + j].put(s + i, c[i]);
            }
        }
        for (int j = 0; j < m; j++) {
            long[][] arr = new long[n][2];
            for (int i = 0; i < n; i++) {
                arr[i] = new long[]{a[i][j], i};
            }
            Arrays.sort(arr, Comparator.comparingLong(o -> o[0]));
            for (int i = 1; i < arr.length; i++) {
                int v1 = (int) arr[i - 1][1] * m + j;
                int v2 = (int) arr[i][1] * m + j;
                maps[v1].put(v2, 0L);
                maps[v2].put(v1, arr[i][0] - arr[i - 1][0]);
            }
        }
        return maps;
    }

    class Pair<K, V> {
        K key;
        V value;

        public Pair(K key, V value) {
            this.key = key;
            this.value = value;
        }
    }
}
