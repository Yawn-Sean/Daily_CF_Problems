import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < t; ez++) {
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            int m = Integer.parseInt(st.nextToken());
            idx = 0;
            for (int i = 1; i <= n; i++) {
                h[i] = -1;
                fa[i] = i;
            }
            // 0 诚实 1 说谎
            for (int i = 0; i < m; i++) {
                st = new StringTokenizer(f.readLine());
                int from = Integer.parseInt(st.nextToken());
                int to = Integer.parseInt(st.nextToken());
                String value = st.nextToken();
                if ("imposter".equals(value)) {
                    add(from, to, 1);
                    add(to, from, 1);
                } else {
                    add(from, to, 0);
                    add(to, from, 0);
                }
                merge(from, to);
            }
            Map<Integer, List<Integer>> map = new HashMap<>();
            for (int i = 1; i <= n; i++)
                map.computeIfAbsent(find(i), v -> new ArrayList<>()).add(i);
            int res = -1;
            for (Integer k : map.keySet()) {
                int ans1 = solve(map, k, 0);
                int ans2 = solve(map, k, 1);
                int max = Math.max(ans1, ans2);
                if (max != -1) {
                    if (res == -1)
                        res = max;
                    else
                        res += max;
                } else {
                    res = -1;
                    break;
                }
            }
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static final int MAXN = (int) 2e5 + 10, MAXM = (int) 1e6 + 10;

    private static int[] h = new int[MAXN], f = new int[MAXN], g = new int[MAXN], fa = new int[MAXN];

    private static int[] e = new int[MAXM], ne = new int[MAXM], w = new int[MAXM];

    private static int idx;

    private static void add(int a, int b, int c) {
        e[idx] = b;
        w[idx] = c;
        ne[idx] = h[a];
        h[a] = idx++;
    }

    private static int find(int x) {
        if (fa[x] != x)
            fa[x] = find(fa[x]);
        return fa[x];
    }

    private static void merge(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y)
            fa[y] = x;
    }

    private static int solve(Map<Integer, List<Integer>> map, int k, int s) {
        List<Integer> list = map.get(k);
        for (Integer id : list)
            f[id] = g[id] = -1;
        return dfs(k, s);
    }

    private static int dfs(int u, int s) {
        f[u] = 1;
        g[u] = s;
        int cnt = s ^ 1;
        for (int i = h[u]; i != -1; i = ne[i]) {
            int v = e[i];
            if (f[v] == -1) {
                int sub = dfs(v, s ^ w[i]);
                if (sub == -1)
                    return -1;
                cnt += sub;
            } else if ((g[u] ^ g[v]) != w[i])
                return -1;
        }
        return cnt;
    }

}
