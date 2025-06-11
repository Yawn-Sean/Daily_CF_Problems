public class Main{
    private static void solve() throws IOException {
        n = sc.nextInt();
        nodes = new int[n + 1];
        ss = sc.nextLine().split(" ");
        for (int i = 1; i <= n; i++) {
            nodes[i] = Integer.parseInt(ss[i - 1]);
        }
        g = new List[n + 1];
        Arrays.setAll(g, e -> new ArrayList<int[]>());
        for (int x = 2; x <= n; x++) {
            int y = sc.nextInt();
            int z = sc.nextInt();
            g[x].add(new int[]{y, z});
            g[y].add(new int[]{x, z});
        }
        dfs(1, 0, 0);
        sc.println(n - ans);
    }

    private static void dfs(int x, int fa, long dis) {
        ans++;
        for (int[] y : g[x]) {
            if (y[0] != fa) {
                long dis0 = dis;
                dis += y[1];
                if (dis < 0) {
                    dis = 0; // 维护距离最大值
                }
                if (dis <= nodes[y[0]]) {
                    dfs(y[0], x, dis);
                }
                dis = dis0;
            }
        }
    }
}
