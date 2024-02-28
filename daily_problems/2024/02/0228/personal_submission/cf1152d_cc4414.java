import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(1, in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            for (int t = 0; t < testNumber; t++) {
                out.println(new Solution().solve(in.nextInt()));
            }
        }
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }

        public long nextLong() {
            return Long.parseLong(next());
        }

        public double nextDouble() {
            return Double.parseDouble(next());
        }
    }
}

class Solution {
    long mod = (long) (1e9 + 7);
    int n;
    long[][][] dp;
    boolean[][] vis;

    public long solve(int n) {
        this.n = n;
        dp = new long[n + 5][n + 5][2];
        vis = new boolean[n + 5][n + 5];
        dfs(1, 0);
        return dp[1][0][1];
    }

    private void dfs(int l, int r) {
        if (vis[l][r]) {
            return;
        }
        vis[l][r] = true;
        if (r == n) {
            return;
        }
        if (l < n) {
            dfs(l + 1, r);
        }
        if (l > r) {
            dfs(l, r + 1);
        }
        dp[l][r][0] = dp[l + 1][r][1] + dp[l][r + 1][1];
        dp[l][r][0] %= mod;
        dp[l][r][1] = dp[l][r][0];
        // 两个dp值最大只差1
        if (l < n) {
            long m = (1 + dp[l + 1][r][0] + dp[l][r + 1][1]) % mod;
            if ((m + mod - dp[l][r][1]) % mod == 1) {
                dp[l][r][1]++;
            }
        }
        if (l > r) {
            long m = (1 + dp[l + 1][r][1] + dp[l][r + 1][0]) % mod;
            if ((m + mod - dp[l][r][1]) % mod == 1) {
                dp[l][r][1]++;
            }
        }
        dp[l][r][1] %= mod;
    }
}
