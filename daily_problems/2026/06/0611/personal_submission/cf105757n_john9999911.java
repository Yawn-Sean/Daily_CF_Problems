// 378129592

import java.util.ArrayList;

public class cf105757n_john9999911 {
    class io {}
    static void solve() {
        int n = io.nextInt();
        ArrayList<Integer>[] g = new ArrayList[n];
        for (int i = 0; i < n; i++) g[i] = new ArrayList<>();
        for (int i = 1; i < n; i++) {
            int p = io.nextInt(), q = io.nextInt();
            g[p].add(q);
            g[q].add(p);
        }
        boolean[] visited = new boolean[n];
        visited[0] = true;
        int tar = 0;
        int[] leaves = new int[]{0,0};
        boolean find = true;
        while (find && ++tar < n) {
            find = false;
            for (int i = 0; i < 2 && !find; i++){
                for (int cur: g[leaves[i]]) {
                    if (visited[cur]) continue;
                    find |= dfs(cur, tar, g, visited);
                    if (!find) continue;
                    leaves[i] = cur;

                    break;
                }
            }
        }

        io.print(tar + " ");
        for (int i = 2; i < n; i++) {
            io.print((g[0].size() >= i ? 1 : 0) + " ");
        }
    }
    static boolean dfs(int cur, int tar, ArrayList<Integer>[] g, boolean[] visited) {
        if (cur == tar) return visited[cur] = true;
        visited[cur] = true;
        for (int x: g[cur]) {
            if (visited[x]) continue;
            if (dfs(x, tar, g, visited)) return true;
        }
        return visited[cur] = false;
    }
}
