# Submission link: https://codeforces.com/contest/965/submission/260889811
class Solution {
    public int solve(int[] a, int l) {
        int w = a.length;
        int[] cnt = new int[w + 1];
        cnt[0] = Integer.MAX_VALUE;
        int j = 0;
        for (int i = 1; i < cnt.length; i++) {
            while (j < i - l) {
                j++;
            }
            while (j < i && a[i - 1] > 0) {
                int t = Math.min(a[i - 1], cnt[j]);
                a[i - 1] -= t;
                cnt[j] -= t;
                cnt[i] += t;
                if (cnt[j] == 0) {
                    j++;
                }
            }
        }
        return cnt[w];
    }
}
