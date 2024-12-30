import java.util.*;
import java.io.*;

public class Main {

    static int[] head, nxt, to;
    static boolean can;
    static List<Integer> edge;
   
    static void solve() {
        int n = sc.nextInt();
        head = new int[n + 1];
        nxt = new int[n << 1];
        to = new int[n << 1];
        for (int i = 1, j = 2; i < n; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            nxt[j] = head[u]; head[u] = j; to[j++] = v;
            nxt[j] = head[v]; head[v] = j; to[j++] = u;
        }
        if ((n % 3) != 0) {
            out.println(-1);
            return;
        }
        can = true;
        edge = new ArrayList<>();
        dfs(0, 1, 0);
        if (!can) {
            out.println(-1);
        } else {
            out.println(edge.size());
            edge.forEach(v -> out.print(v + " "));
            out.println();
        }
    }

    static int dfs(int f, int u, int ep) {
        int rest = 1;
        for (int e = head[u], v = to[e]; e != 0; e = nxt[e], v = to[e]) {
            if (v != f) {
                rest += dfs(u, v, e);
            }
        }
        if (rest > 3) {
            can = false;
        }
        if (rest == 3) {
            if (f != 0) {
                edge.add(ep >> 1);
            }
        }
        return rest % 3;
    }
  
}
