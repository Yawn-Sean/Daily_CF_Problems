# Submission link: https://codeforces.com/contest/914/submission/260891656
class Solution {
    public long solve(String s, int k) {
        if (k == 0) {
            return 1;
        }
        if (k == 1) {
            return s.length() - 1;
        }
        long mod = (long) (1e9 + 7);
        char[] chars = s.toCharArray();
        int n = chars.length;
        Factorial fac = new Factorial(n + 5, (int) mod);
        int[] arr = new int[n + 5];
        for (int i = 2; i < arr.length; i++) {
            arr[i] = arr[Integer.bitCount(i)] + 1;
        }
        long[] cnt = new long[n + 5];
        int cur = 0;
        for (char c : chars) {
            if (c == '1') {
                cur++;
            }
        }
        cnt[cur]++;
        for (int i = n - 1; i >= 0; i--) {
            if (chars[i] == '0') {
                continue;
            }
            cur--;
            int l = n - 1 - i;
            for (int j = 0; j <= l; j++) {
                cnt[cur + j] += fac.comb(l, j);
                cnt[cur + j] %= mod;
            }
        }
        long ans = 0;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == k - 1) {
                ans += cnt[i];
            }
        }
        return (ans % mod + mod) % mod;
    }
}
