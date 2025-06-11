import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), m = sc.nextInt();
        int[] arr = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            arr[i] = sc.nextInt();
        }
        int[][] query = new int[m][3];
        int[] ans = new int[m];
        for (int i = 0; i < m; i++) {
            query[i][0] = sc.nextInt();
            query[i][1] = sc.nextInt();
            query[i][2] = i;
        }
        Arrays.sort(query, (i, j) -> i[1] - j[1]);
        HashMap<Integer, Integer> map = new HashMap<>();
        SegTree tree = new SegTree(n);
        int i = 0;
        for (int[] q : query) {
            while (i < q[1]) {
                i++;
                if (map.containsKey(arr[i])) {
                    int t = map.get(arr[i]);
                    tree.set(t, i - t);
                }
                map.put(arr[i], i);
            }
            ans[q[2]] = tree.query(q[0], q[1]);
        }
        for (int v : ans) {
            out.println(v == Integer.MAX_VALUE ? -1 : v);
        }
    }

    static class SegTree {
        private int[] min;
        private int N;

        public SegTree(int len) {
            N = len;
            min = new int[N << 2];
            Arrays.fill(min, Integer.MAX_VALUE);
        }

        public void set(int idx, int val) {
            set(idx, val, 1, N, 1);
        }

        private void set(int o, int v, int l, int r, int i) {
            if (l == r) {
                min[i] = v;
                return;
            }
            int m = (l + r) >> 1;
            if (o <= m) {
                set(o, v, l, m, i << 1);
            } else {
                set(o, v, m + 1, r, i << 1 | 1);
            }
            min[i] = Math.min(min[i << 1], min[i << 1 | 1]);
        }

        public int query(int left, int right) {
            return query(left, right, 1, N, 1);
        }

        private int query(int L, int R, int l, int r, int i) {
            if (L <= l && r <= R) {
                return min[i];
            }
            int m = (l + r) >> 1;
            int ans = Integer.MAX_VALUE;
            if (L <= m) {
                ans = Math.min(ans, query(L, R, l, m, i << 1));
            } 
            if (R > m) {
                ans = Math.min(ans, query(L, R, m + 1, r, i << 1 | 1));
            }
            return ans;
        }
    }

}
