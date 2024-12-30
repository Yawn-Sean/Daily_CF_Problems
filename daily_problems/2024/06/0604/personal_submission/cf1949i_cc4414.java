# Submission link: https://codeforces.com/contest/1949/submission/264101759
class Solution {
    public boolean solve(long[][] a) {
        double eps = 1e-9;
        int n = a.length;
        boolean[][] con = new boolean[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long dx = a[i][0] - a[j][0];
                long dy = a[i][1] - a[j][1];
                if (Math.sqrt(dx * dx + dy * dy) - a[i][2] - a[j][2] < eps) {
                    con[i][j] = true;
                    con[j][i] = true;
                }
            }
        }
        boolean[] vis = new boolean[n];
        int[] color = new int[n];
        for (int i = 0; i < n; i++) {
            if (vis[i]) {
                continue;
            }
            int[] cnt = new int[2];
            cnt[0] = 1;
            boolean b = true;
            ArrayDeque<Integer> deque = new ArrayDeque<>();
            deque.add(i);
            vis[i] = true;
            while (!deque.isEmpty()) {
                Integer remove = deque.remove();
                for (int j = 0; j < n; j++) {
                    if (con[remove][j]) {
                        if (vis[j]) {
                            if (color[remove] == color[j]) {
                                b = false;
                            }
                            continue;
                        }
                        deque.add(j);
                        vis[j] = true;
                        color[j] = color[remove] ^ 1;
                        cnt[color[j]]++;
                    }
                }
            }
            if (b && cnt[0] != cnt[1]) {
                return true;
            }
        }
        return false;
    }
}
