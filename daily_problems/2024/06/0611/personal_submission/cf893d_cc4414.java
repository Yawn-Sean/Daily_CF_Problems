# Submission link: https://codeforces.com/contest/893/submission/265164074
class Solution {
    public int solve(int[] a, int d) {
        int n = a.length;
        List<int[]> list = new ArrayList<>();
        int max = 0;
        int cur = 0;
        for (int i = 0; i < n; i++) {
            cur += a[i];
            max = Math.max(max, cur);
            if (max > d) {
                return -1;
            }
            if (a[i] == 0) {
                if (cur >= 0) {
                    continue;
                }
                list.add(new int[]{max, -cur});
                max = 0;
                cur = 0;
            }
        }
        int ans = list.size();
        int s = 0;
        for (int i = list.size() - 1; i > 0; i--) {
            int[] arr = list.get(i);
            s += arr[1];
            if (s + arr[0] <= d) {
                ans--;
            } else {
                s = 0;
            }
        }
        return ans;
    }
}
