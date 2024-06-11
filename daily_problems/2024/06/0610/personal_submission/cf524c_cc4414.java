# Submission link: https://codeforces.com/contest/524/submission/265038094
class Solution {
    public int[] solve(int[] a, int[] queries, int k) {
        int n = a.length;
        Set<Integer> set = new HashSet<>();
        for (int v : a) {
            set.add(v);
        }
        int q = queries.length;
        int[] ans = new int[q];
        for (int i = 0; i < queries.length; i++) {
            int query = queries[i];
            ans[i] = Integer.MAX_VALUE;
            for (int j = 0; j < n; j++) {
                for (int t = 0; t <= k; t++) {
                    int c = query - t * a[j];
                    if (c < 0) {
                        break;
                    }
                    if (c == 0) {
                        ans[i] = Math.min(ans[i], t);
                        break;
                    }
                    for (int t2 = 1; t2 <= k - t; t2++) {
                        if (c % t2 != 0 || !set.contains(c / t2)) {
                            continue;
                        }
                        ans[i] = Math.min(ans[i], t + t2);
                        break;
                    }
                }
            }
            if (ans[i] == Integer.MAX_VALUE || ans[i] > k) {
                ans[i] = -1;
            }
        }
        return ans;
    }
}
