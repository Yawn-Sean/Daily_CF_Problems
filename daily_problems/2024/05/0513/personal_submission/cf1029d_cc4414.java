# Submission link: https://codeforces.com/contest/1029/submission/260746947
class Solution {
    public long solve(int[] a, int k) {
        int n = a.length;
        Map<Integer, Integer>[] maps = new HashMap[11];
        long[] pow10 = new long[11];
        pow10[0] = 1;
        for (int i = 1; i < maps.length; i++) {
            pow10[i] = pow10[i - 1] * 10;
            long m = pow10[i] % k;
            maps[i] = new HashMap<>();
            for (int j = 0; j < n; j++) {
                int t = (int) (a[j] % k * m % k);
                maps[i].put(t, maps[i].getOrDefault(t, 0) + 1);
            }
        }
        long ans = 0;
        for (int i = 0; i < n; i++) {
            int t = (k - a[i] % k) % k;
            int l = String.valueOf(a[i]).length();
            ans += maps[l].getOrDefault(t, 0);
            if (a[i] % k * (pow10[l] % k) % k == t) {
                ans--;
            }
        }
        return ans;
    }
}
