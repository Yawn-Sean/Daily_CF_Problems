import java.io.*;
import java.util.*;

public class Main {
   
    static int MOD = (int) 1e9 + 7;
    static long[] A = new long[100001];
    static {
        A[0] = 1;
        for (int i = 1; i <= 100000; i++) {
            A[i] = A[i - 1] * 2 % MOD;
        }
    }

    static int n, m;
    static int[] head, nxt, to;
    static int[] dfn, low, stk, dcc;
    static boolean[] bri;
    static int ts, top, no;
    static List<Integer>[] garph;
    static int[] val;
    static int[][] pa, cnt;
    static int[] dep;


    static void solve() {
        n = sc.nextInt();
        m = sc.nextInt();
        head = new int[n + 1];
        nxt = new int[(m + 1) << 1];
        to = new int[(m + 1) << 1];
        for (int i = 0, j = 2; i < m; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            nxt[j] = head[u]; head[u] = j; to[j++] = v;
            nxt[j] = head[v]; head[v] = j; to[j++] = u;
        }
        dfn = new int[n + 1];
        low = new int[n + 1];
        stk = new int[n + 1];
        dcc = new int[n + 1];
        bri = new boolean[(m + 1) << 1];
        ts = top = no = 0;
        tarjan(1, 0);
        garph = new List[no + 1];
        val = new int[no + 1];
        Arrays.setAll(garph, v -> new ArrayList<>());
        for (int u = 1; u <= n; u++) {
            val[dcc[u]]++;
        }
        for (int e = 2; e < (m + 1) << 1; e++) {
            if (bri[e]) {
                garph[dcc[to[e ^ 1]]].add(dcc[to[e]]);
            }
        }
        pa = new int[no + 1][18];
        cnt = new int[no + 1][18];
        dep = new int[no + 1];
        dfs(0, 1, 1);
        for (int q = sc.nextInt(); q > 0; q--) {
            int u = dcc[sc.nextInt()], v = dcc[sc.nextInt()], a = lca(u, v), du = dep[u] - dep[a], dv = dep[v] - dep[a];
            int count = (val[a] > 1 ? -1 : 0) + (val[u] > 1 ? 1 : 0) + (val[v] > 1 ? 1 : 0);
            for (int i = 17; i >= 0; i--) {
                if ((du >> i & 1) != 0) {
                    count += cnt[u][i];
                    u = pa[u][i];
                }
                if ((dv >> i & 1) != 0) {
                    count += cnt[v][i];
                    v = pa[v][i];
                }
            }
            out.println(A[count]);
        }
    }

    static int lca(int x, int y) {
        int dx = dep[x], dy = dep[y];
        if (dx > dy) {
            x = jump(x, dx - dy);
        } else if (dx < dy) {
            y = jump(y, dy - dx);
        }
        if (x == y) {
            return x;
        }
        for (int i = 17; i >= 0; i--) {
            if (pa[x][i] != pa[y][i]) {
                x = pa[x][i];
                y = pa[y][i];
            }
        }
        return pa[x][0];
    }

    static int jump(int o, int d) {
        for (int i = 0; i < 18; i++) {
            if ((d >> i & 1) != 0) {
                o = pa[o][i];
            }
        }
        return o;
    }

    static void dfs(int f, int u, int d) {
        dep[u] = d;
        pa[u][0] = f;
        cnt[u][0] = val[f] > 1 ? 1 : 0;
        for (int i = 1; i < 18; i++) {
            pa[u][i] = pa[pa[u][i - 1]][i - 1];
            cnt[u][i] = cnt[u][i - 1] + cnt[pa[u][i - 1]][i - 1];
        }
        for (int v : garph[u]) {
            if (v != f) {
                dfs(u, v, d + 1);
            }
        }
    }

    static void tarjan(int u, int ep) {
        dfn[u] = low[u] = ++ts;
        stk[++top] = u;
        for (int e = head[u], v = to[e]; e != 0; e = nxt[e], v = to[e]) {
            if (dfn[v] == 0) {
                tarjan(v, e);
                low[u] = Math.min(low[u], low[v]);
                if (low[v] > dfn[u]) {
                    bri[e] = bri[e ^ 1] = true;
                }
            } else if (ep != (e ^ 1)) {
                low[u] = Math.min(low[u], dfn[v]);
            }
        }
        if (dfn[u] == low[u]) {
            no++;
            int o;
            do {
                o = stk[top--];
                dcc[o] = no;
            } while (o != u);
        }
    }

}
