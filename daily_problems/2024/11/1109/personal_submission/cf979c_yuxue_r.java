import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int x = Integer.parseInt(input[1]);
        int y = Integer.parseInt(input[2]);

        List<List<Integer>> path = new ArrayList<>();
        for (int i = 0; i <= n; i++) {
            path.add(new ArrayList<>());
        }

        for (int i = 0; i < n - 1; i++) {
            String[] edge = br.readLine().split(" ");
            int u = Integer.parseInt(edge[0]);
            int v = Integer.parseInt(edge[1]);
            path.get(u).add(v);
            path.get(v).add(u);
        }

        int[] parent = new int[n + 1];
        int[] size = new int[n + 1];
        Arrays.fill(size, 1);

        dfs(x, -1, path, parent, size);

        long ans = size[y];
        while (parent[y] != x) {
            y = parent[y];
        }
        ans *= n - size[y];
        bw.write(Long.toString(1L * n * (n - 1) - ans));
        bw.newLine();
        bw.flush();
        bw.close();
        br.close();
    }

    private static void dfs(int u, int p, List<List<Integer>> path, int[] parent, int[] size) {
        parent[u] = p;
        for (int v : path.get(u)) {
            if (v != p) {
                dfs(v, u, path, parent, size);
                size[u] += size[v];
            }
        }
    }
}
