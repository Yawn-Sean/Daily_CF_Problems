// https://codeforces.com/contest/575/submission/275465240
class Solution {
    public long solve(int[][] a, int x) {
        int n = a.length;
        int m = n * 2 + 1;
        int[] arr = new int[m];
        for (int i = 0; i < a.length; i++) {
            arr[i * 2] = a[i][0];
            arr[i * 2 + 1] = a[i][1];
        }
        arr[m - 1] = x;
        Arrays.sort(arr);
        long[] dp = new long[m];
        for (int i = 0; i < m; i++) {
            dp[i] = Math.abs(arr[i] - x);
        }
        for (int i = 1; i <= n; i++) {
            int l = -1;
            int r = -1;
            for (int j = 0; j < m; j++) {
                if (arr[j] == a[i - 1][0]) {
                    l = j;
                }
                if (arr[j] == a[i - 1][1]) {
                    r = j;
                }
            }
            for (int j = r + 1; j < m; j++) {
                dp[j] = Math.min(dp[j] + arr[j] - arr[r], dp[j - 1] + arr[j] - arr[j - 1]);
            }
            for (int j = l - 1; j >= 0; j--) {
                dp[j] = Math.min(dp[j] + arr[l] - arr[j], dp[j + 1] + arr[j + 1] - arr[j]);
            }
        }
        return Arrays.stream(dp).min().orElse(0);
    }
}
