# Submission link: https://codeforces.com/contest/1286/submission/265050394
class Solution {
    int[][] arr;
    Set<Integer>[] sets;
    int[] ans;
    int cur = 1;

    public int[] solve(int[][] arr) {
        this.arr = arr;
        int n = arr.length;
        ans = new int[n];
        sets = new Set[n];
        for (int i = 0; i < n; i++) {
            sets[i] = new HashSet<>();
        }
        int root = -1;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i][0] == -1) {
                root = i;
                continue;
            }
            sets[arr[i][0]].add(i);
        }
        int c = dfs0(root);
        if (c == -1) {
            return null;
        }
        dfs(root);
        return ans;
    }

    private int dfs0(int v) {
        int cnt = 1;
        for (Integer w : sets[v]) {
            int c = dfs0(w);
            if (c == -1) {
                return -1;
            }
            cnt += c;
        }
        if (cnt - 1 < arr[v][1]) {
            return -1;
        }
        return cnt;
    }

    private void dfs(int v) {
        ans[v] = arr[v][1] + cur;
        for (Integer w : sets[v]) {
            dfs(w);
        }
        dfs1(v, ans[v]);
        cur++;
    }

    private void dfs1(int v, int k) {
        for (Integer w : sets[v]) {
            if (ans[w] >= k) {
                ans[w]++;
            }
            dfs1(w, k);
        }
    }
}
