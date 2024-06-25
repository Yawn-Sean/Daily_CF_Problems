# Submission link: https://codeforces.com/contest/301/submission/262324172
class Solution {
    public int solve(int[] a, int[][] points, int d) {
        int n = a.length;
        int[][] dis = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                dis[i][j] = (Math.abs(points[i][0] - points[j][0]) + Math.abs(points[i][1] - points[j][1])) * d - a[j];
            }
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dis[i][j] = Math.min(dis[i][j], dis[i][k] + dis[k][j]);
                }
            }
        }
        return dis[0][n - 1];
    }
}
