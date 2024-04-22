
public class cf1027d_WindLY {
    // 对于每个连通分量，找环中最小代价
    // https://codeforces.com/contest/1027/submission/254024700
    public static void main(String[] args) throws IOException {
        int n = ni();
        int[] a = na();
        int[] next = na();
        for (int i = 0; i < n; i++) {
            next[i]--;
        }
        boolean[] vis = new boolean[n];
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (vis[i]) continue;
            ans += f(i, vis, next, a);
        }
        out.println(ans);
        out.flush();
    }
    static int f(int i, boolean[] vis, int[] next, int[] a) {
        Set<Integer> set = new HashSet<>(); // 存当前遍历节点，找有无环
        vis[i] = true;
        set.add(i);
        while (!vis[next[i]]) {
            i = next[i];
            vis[i] = true;
            set.add(i);
        }
        if (set.contains(next[i])) { // 当前遍历有环，找环中最小值
            int s = next[i];
            int min = a[s];
            i = next[i];
            while (next[i] != s) {
                i = next[i];
                min = Math.min(min, a[i]);
            }
            return min;
        } else return 0; // 当前无环，遇到之前的连通分量，并入之前的子集，无需额外放夹子
    }
}