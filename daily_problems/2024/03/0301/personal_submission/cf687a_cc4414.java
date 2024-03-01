import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            for (int t = 0; t < testNumber; t++) {
                int n = in.nextInt();
                int m = in.nextInt();
                int[][] edges = new int[m][2];
                for (int i = 0; i < edges.length; i++) {
                    edges[i] = new int[]{in.nextInt() - 1, in.nextInt() - 1};
                }
                List<Integer>[] solve = new Solution().solve(edges, n);
                if (solve == null) {
                    out.println(-1);
                } else {
                    for (List<Integer> list : solve) {
                        out.println(list.size());
                        for (Integer v : list) {
                            out.print(v + 1 + " ");
                        }
                        out.println();
                    }
                }
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
    int[] arr;
    Set<Integer>[] sets;
    boolean[] vis;

    public List<Integer>[] solve(int[][] edges, int n) {
        arr = new int[n];
        Arrays.fill(arr, -1);
        sets = new Set[n];
        for (int i = 0; i < n; i++) {
            sets[i] = new HashSet<>();
        }
        for (int[] edge : edges) {
            sets[edge[0]].add(edge[1]);
            sets[edge[1]].add(edge[0]);
        }
        vis = new boolean[n];
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            if (!dfs(i, 0)) {
                return null;
            }
        }
        List<Integer>[] ans = new List[2];
        ans[0] = new ArrayList<>();
        ans[1] = new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            ans[arr[i]].add(i);
        }
        return ans;
    }

    private boolean dfs(int v, int d) {
        if (vis[v]) {
            return arr[v] == d;
        }
        arr[v] = d;
        vis[v] = true;
        boolean ans = true;
        for (Integer w : sets[v]) {
            ans &= dfs(w, d ^ 1);
        }
        return ans;
    }
}
