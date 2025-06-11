# Submission link: https://codeforces.com/contest/1056/submission/261446708
class Solution {
    int[] cnt;
    Set<Integer>[] sets;

    public int[] solve(int[] p) {
        int n = p.length;
        int[] ans = new int[n];
        if (n == 1) {
            ans[0] = 1;
            return ans;
        }
        cnt = new int[n];
        sets = new Set[n];
        for (int i = 0; i < sets.length; i++) {
            sets[i] = new HashSet<>();
        }
        for (int i = 1; i < p.length; i++) {
            sets[p[i]].add(i);
        }
        dfs(0);
        int[] arr = new int[n];
        for (int c : cnt) {
            arr[c]++;
        }
        int sum = 0;
        int j = 0;
        for (int i = 0; i < arr.length; i++) {
            sum += arr[i];
            while (j < sum) {
                ans[j] = i;
                j++;
            }
        }
        return ans;
    }

    private int dfs(int v) {
        if (sets[v].isEmpty()) {
            cnt[v] = 1;
            return 1;
        }
        for (Integer w : sets[v]) {
            cnt[v] += dfs(w);
        }
        return cnt[v];
    }
}
