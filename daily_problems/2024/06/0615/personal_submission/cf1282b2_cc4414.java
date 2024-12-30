// Submission link: https://codeforces.com/contest/1282/submission/265889651
class Solution {
    public int solve(int[] a, int p, int k) {
        int n = a.length;
        Arrays.sort(a);
        int max = 0;
        int s = 0;
        for (int i = 0; i < k; i++) {
            int sum = s;
            int cnt = i;
            int j = i + k - 1;
            while (j < n && sum + a[j] <= p) {
                sum += a[j];
                cnt += k;
                j += k;
            }
            max = Math.max(max, cnt);
            s += a[i];
            if (s > p) {
                break;
            }
        }
        return max;
    }
}
