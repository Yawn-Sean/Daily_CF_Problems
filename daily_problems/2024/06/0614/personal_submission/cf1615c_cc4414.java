// Submission link: https://codeforces.com/contest/1615/submission/265750811
class Solution {
    public int solve(String a, String b) {
        char[] chars1 = a.toCharArray();
        char[] chars2 = b.toCharArray();
        int n = chars1.length;
        int ans = n + 5;
        int[] cnt = new int[2];
        for (int i = 0; i < n; i++) {
            if (chars1[i] == chars2[i]) {
                continue;
            }
            cnt[chars1[i] - '0']++;
        }
        if (cnt[0] == cnt[1]) {
            ans = cnt[0] * 2;
        }
        for (int i = 0; i < chars1.length; i++) {
            chars1[i] = chars1[i] == '0' ? '1' : '0';
        }
        cnt = new int[2];
        for (int i = 0; i < n; i++) {
            if (chars1[i] == chars2[i]) {
                continue;
            }
            cnt[chars1[i] - '0']++;
        }
        if (cnt[0] == cnt[1] + 1) {
            ans = Math.min(ans, cnt[0] * 2 - 1);
        }
        return ans == n + 5 ? -1 : ans;
    }
}
