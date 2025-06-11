import java.util.*;
import java.io.*;

public class Main {

    static int MOD = 998244353;

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        int[] a = new int[n], b = new int[n], idx = new int[n + 1];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
            idx[a[i]] = i;
        }
        for (int i = 1; i <= k; i++) {
            b[idx[sc.nextInt()]] = i;
        }
        for (int i = 0; i < n; i++) {
            idx[b[i]] = i;
        }
        int[] stk = new int[n], left = new int[n], right = new int[n];
        int s = -1;
        for (int i = 0; i < n; i++) {
            if (b[i] == 0) {
                continue;
            }
            while (s != -1 && b[stk[s]] < b[i]) {
                int j = stk[s--];
                right[j] = i - 1;
                left[j] = s == -1 ? 0 : (stk[s] + 1);
            }
            stk[++s] = i;
        }
        while (s != -1) {
            int j = stk[s--];
            right[j] = n - 1;
            left[j] = s == -1 ? 0 : (stk[s] + 1);
        }
        IndexTree tree = new IndexTree(n);
        for (int i = 1; i <= n; i++) {
            tree.add(i, 1);
        }
        long ans = 1;
        for (int i = 1; i <= k; i++) {
            int j = idx[i], l = left[j], r = right[j];
            long lv = tree.range(l + 1, j), rv = tree.range(j + 2, r + 1);
            if (lv == 0 && rv == 0) {
                ans = 0;
                break;
            }
            if (lv != 0 && rv != 0) {
                ans = (ans * 2) % MOD;
            }
            tree.add(j + 1, -1);
        }
        out.println(ans);
    }

    static class IndexTree {
        private int[] sum;
        private int N;

        public IndexTree(int len) {
            N = len + 1;
            sum = new int[N];
        }

        public void add(int i, int v) {
            while (i < N) {
                sum[i] += v;
                i += i & -i;
            }
        }

        public int query(int i) {
            int ans = 0;
            while (i > 0) {
                ans += sum[i];
                i -= i & -i;
            }
            return ans;
        }

        public int range(int l , int r) {
            if (l > r) {
                return 0;
            }
            return query(r) - query(l - 1);
        }
    }

}
