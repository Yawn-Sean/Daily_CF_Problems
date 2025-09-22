import java.io.*;
import java.util.*;

public class Main {
    static int n, m;
    static List<List<Integer>> g;
    static List<Integer> nodes;
    static int[] vis, color;

    private static void dfs(int u, int digit){
        vis[u] = 1;
        nodes.add(u);

        g.get(u).forEach(v -> {
            boolean is = (color[u] & color[v] & (1<<digit)) > 0;
            if (vis[v] == 0 && (color[u]&color[v]&(1<<digit)) > 0){
                dfs(v, digit);
            }
        });
    }

    private static void solve(){
        n = sc.nextInt();
        m = sc.nextInt();
        color = new int[n];
        vis = new int[n];
        g = new ArrayList<>();
        nodes = new ArrayList<>();

        int[][] res = new int[n][n];

        for (int i = 0; i < n; ++ i){
            res[i][i] = 1;
            color[i] = sc.nextInt();
            g.add(new ArrayList<>());
        }
        for (int i = 0, u, v; i < m; ++ i){
            u = sc.nextInt() - 1;
            v = sc.nextInt() - 1;
            g.get(u).add(v);
            g.get(v).add(u);
        }

        for (int i = 0; i < 30; ++ i){
            for (int u = 0; u < n; ++ u){
                if (vis[u] == 1) continue;
                dfs(u, i);
                int len = nodes.size();
                for (int i1 = 0; i1 < len; ++ i1){
                    for (int i2 = i1+1; i2 < len; ++ i2){
                        res[nodes.get(i1)][nodes.get(i2)] = 1;
                        res[nodes.get(i2)][nodes.get(i1)] = 1;
                    }
                }
                nodes.clear();
            }
            for (int u = 0; u < n; ++ u){
                vis[u] = 0;
            }
        }

        for (int i = 0; i < n; ++ i){
            for (int j = 0; j < n; ++ j){
                out.print(res[i][j]);
            }
            out.println();
        }
    }
}
