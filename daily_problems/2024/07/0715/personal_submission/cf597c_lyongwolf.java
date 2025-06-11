import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt() + 1;
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        if (k > n) {
            out.println(0);
            return;
        }
        long[][] dp = new long[n][k + 1];
        Fenwick[] tree = new Fenwick[k + 1];
        for (int i = 1; i <= k; i++) {
            tree[i] = new Fenwick(n);
        }
        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            dp[i][1] = 1;
            tree[1].add(a[i], 1);
            for (int j = k; j >= 2; j--) {
                dp[i][j] = tree[j - 1].rang(a[i] + 1, n);
                tree[j].add(a[i], dp[i][j]);
            }
            ans += dp[i][k];
        }
        out.println(ans);
    }

    static class Fenwick {
        private long[] sum;
        private int N;

        public Fenwick(int len) {
            N = len + 1;
            sum = new long[N];
        }

        public void add(int i, long v) {
            while (i < N) {
                sum[i] += v;
                i += i & -i;
            }
        }

        public long query(int i) {
            long ans = 0;
            while (i > 0) {
                ans += sum[i];
                i -= i & -i;
            }
            return ans;
        }

        public long rang(int l, int r) {
            return l > r ? 0 : query(r) - query(l - 1);
        }
    }

}
