import java.util.*;
import java.io.*;
public class cf1076e_WindLY {
    static BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
    static PrintWriter out = new PrintWriter(System.out);
    public static void main(String[] args) throws IOException {
        int n = ni();
        // 1 ~ n
        List<Integer>[] nexts = new List[n + 1];
        Arrays.setAll(nexts, e -> new ArrayList<>());
        for (int i = 0; i < n - 1; i++) { // 邻接表
            int[] in = na();
            int x = in[0], y = in[1];
            nexts[x].add(y);
            nexts[y].add(x);
        }
        int m = ni();
        List<int[]>[] op = new List[n + 1]; // 存各节点的操作
        Arrays.setAll(op, e -> new ArrayList<>());
        long[] a = new long[n + 1]; // 存节点值
        while (m-- > 0) {
            int[] in = na();
            int v = in[0], d = in[1], x = in[2];
            op[v].add(new int[]{d, x});
        }
        f(1, 0, 1, nexts, op, a, new boolean[n + 1], new long[n + 1], n); // 根节点1开始dfs
        for (int i = 0; i < n; i++) {
            out.print(a[i + 1] + " ");
        }
        out.flush();
    }
    static void f(int node, long cur, int deep, List<Integer>[] nexts, List<int[]>[] op, long[] a, boolean[] vis, long[] d, int n) {
        vis[node] = true;
        cur += d[deep];
        for (int[] o: op[node]) { // d x  修改差分
            cur += o[1];
            if (deep + o[0] + 1 <= n) d[deep + o[0] + 1] -= o[1];
        }
        a[node] = cur;
        for (int next: nexts[node]) { // dfs
            if (vis[next]) continue;
            f(next, cur, deep + 1, nexts, op, a, vis, d, n);
        }
        for (int[] o: op[node]) { // 回溯 撤销操作
            if (deep + o[0] + 1 <= n) d[deep + o[0] + 1] += o[1];
        }
    }
    static int ni() throws IOException {
        return Integer.parseInt(sc.readLine());
    }
    static int[] na() throws IOException {
        String[] in = sc.readLine().split(" ");
        int n = in.length;
        int[] ans = new int[n];
        for (int i = 0; i < n; i++) {
            ans[i] = Integer.parseInt(in[i]);
        }
        return ans;
    }
}
