// Submission link: https://codeforces.com/contest/666/submission/265491337
class Solution {
    public int[] solve(int[][] edges, int n) {
        int[] ans = new int[4];
        int[][] dis = new int[n][n];
        Set<Integer>[] sets = new Set[n];
        for (int i = 0; i < n; i++) {
            sets[i] = new HashSet<>();
        }
        for (int[] edge : edges) {
            sets[edge[0]].add(edge[1]);
        }
        for (int i = 0; i < n; i++) {
            Arrays.fill(dis[i], -1);
            boolean[] vis = new boolean[n];
            ArrayDeque<Integer> deque = new ArrayDeque<>();
            vis[i] = true;
            dis[i][i] = 0;
            deque.add(i);
            while (!deque.isEmpty()) {
                Integer first = deque.removeFirst();
                for (int j : sets[first]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        dis[i][j] = dis[i][first] + 1;
                        deque.addLast(j);
                    }
                }
            }
        }
        int[][][] dis1 = new int[n][3][2];
        int[][][] dis2 = new int[n][3][2];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dis1[i][j][0] = -1;
                dis2[i][j][0] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    dis[i][j] = -1;
                }
                if (dis[i][j] > dis1[i][0][0]) {
                    dis1[i][2][0] = dis1[i][1][0];
                    dis1[i][2][1] = dis1[i][1][1];
                    dis1[i][1][0] = dis1[i][0][0];
                    dis1[i][1][1] = dis1[i][0][1];
                    dis1[i][0][0] = dis[i][j];
                    dis1[i][0][1] = j;
                } else if (dis[i][j] > dis1[i][1][0]) {
                    dis1[i][2][0] = dis1[i][1][0];
                    dis1[i][2][1] = dis1[i][1][1];
                    dis1[i][1][0] = dis[i][j];
                    dis1[i][1][1] = j;
                } else if (dis[i][j] > dis1[i][2][0]) {
                    dis1[i][2][0] = dis[i][j];
                    dis1[i][2][1] = j;
                }
                if (dis[i][j] > dis2[j][0][0]) {
                    dis2[j][2][0] = dis2[j][1][0];
                    dis2[j][2][1] = dis2[j][1][1];
                    dis2[j][1][0] = dis2[j][0][0];
                    dis2[j][1][1] = dis2[j][0][1];
                    dis2[j][0][0] = dis[i][j];
                    dis2[j][0][1] = i;
                } else if (dis[i][j] > dis2[j][1][0]) {
                    dis2[j][2][0] = dis2[j][1][0];
                    dis2[j][2][1] = dis2[j][1][1];
                    dis2[j][1][0] = dis[i][j];
                    dis2[j][1][1] = i;
                } else if (dis[i][j] > dis2[j][2][0]) {
                    dis2[j][2][0] = dis[i][j];
                    dis2[j][2][1] = i;
                }
            }
        }
        int max = 0;
        for (int i = 0; i < n; i++) {
            if (dis1[i][0][0] == -1) {
                continue;
            }
            for (int j = 0; j < n; j++) {
                if (i == j || dis[j][i] == -1 || dis2[j][0][0] == -1) {
                    continue;
                }
                for (int l = 0; l < 3; l++) {
                    if (dis2[j][l][1] == i || dis2[j][l][0] == -1) {
                        continue;
                    }
                    for (int r = 0; r < 3; r++) {
                        if (dis1[i][r][1] == j || dis1[i][r][0] == -1) {
                            continue;
                        }
                        if (dis2[j][l][1] == dis1[i][r][1]) {
                            continue;
                        }
                        if (dis2[j][l][0] + dis[j][i] + dis1[i][r][0] > max) {
                            max = dis2[j][l][0] + dis[j][i] + dis1[i][r][0];
                            ans[0] = dis2[j][l][1];
                            ans[1] = j;
                            ans[2] = i;
                            ans[3] = dis1[i][r][1];
                        }
                    }
                }
            }
        }
        return ans;
    }
}
