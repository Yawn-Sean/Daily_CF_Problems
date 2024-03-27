public class cf924b_WindLY {
    // 法1：二分找右界
    // https://codeforces.com/contest/924/submission/253479332
    static void solve1(int n, int U, int[] a) {
        double max = -1;
        for (int i = 0; i < n - 2; i++) {
            int l = i + 2, r = n - 1;
            int v = a[i] + U;
            while (l <= r) {
                int m = l + r >> 1;
                if (a[m] <= v) l = m + 1;
                else r = m - 1;
            }
            if (r == i + 1) continue;
            max = Math.max((double) (a[r] - a[i + 1]) / (double) (a[r] - a[i]), max);
        }
        out.println(max);
    }

    // 法2：不定长滑动窗口，遍历左界，找右界
    // https://codeforces.com/contest/924/submission/253480431
    static void solve2(int n, int U, int[] a) {
        double max = -1;
        int r = 0;
        for (int l = 0; l < n - 2; l++) {
            while (r < n && a[r] <= a[l] + U) r++;
            if (r - 1 > l + 1) max = Math.max(max, (double) (a[r - 1] - a[l + 1]) / (double) (a[r - 1] - a[l]));
        }
        out.println(max);
    }
}
