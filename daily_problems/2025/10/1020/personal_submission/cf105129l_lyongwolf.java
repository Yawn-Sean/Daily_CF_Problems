public class Main {

    long[] ans = new long[(1 << 15) - 1];
    boolean[][] ok = new boolean[(1 << 15) - 1][51];

    Main() {
        int[] p = {
            2, 3, 5, 7, 11,
            13, 17, 19, 23, 29,
            31, 37, 41, 43, 47
        };
        for (int s = 1, j = 0; s < 1 << 15; s++) {
            long v = 1;
            for (int i = 0; i < 15; i++) {
                if ((s >> i & 1) != 0) {
                    v *= p[i];
                }
            }
            ans[j++] = v;
        }
        Arrays.sort(ans);
        for (int i = 0; i < (1 << 15) - 1; i++) {
            for (int j = 2; j <= 50; j++) {
                ok[i][j] = gcd(ans[i], j) > 1;
            }
        }
    }

    void solve() {
        boolean[] vis = new boolean[51];
        int n = ni();
        for (int i = 0; i < n; i++) {
            vis[ni()] = true;
        }
        o: for (int i = 0; i < (1 << 15) - 1; i++) {
            for (int j = 2; j <= 50; j++) {
                if (vis[j]) {
                    if (!ok[i][j]) {
                        continue o;
                    }
                }
            }
            println(ans[i]);
            return;
        }
    }

    long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void main(String[] args) {
        new Main() {{for (int i = ni(); i > 0; i--) solve();}}.flush();
    }
}
