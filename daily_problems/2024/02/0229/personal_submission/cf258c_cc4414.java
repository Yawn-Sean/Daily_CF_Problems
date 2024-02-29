import java.io.*;
import java.math.BigInteger;
import java.util.Arrays;
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
                int n = in.nextInt();
                int[] a = new int[n];
                for (int i = 0; i < a.length; i++) {
                    a[i] = in.nextInt();
                }
                out.println(new Solution().solve(a));
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
    public long solve(int[] a) {
        long mod = (long) (1e9 + 7);
        long ans = 1;
        BigInteger bigMod = BigInteger.valueOf(mod);
        int max = Arrays.stream(a).max().orElse(0);
        int[] cntNum = new int[max + 1];
        for (int v : a) {
            cntNum[v]++;
        }
        for (int i = 1; i < cntNum.length; i++) {
            cntNum[i] += cntNum[i - 1];
        }
        int[] cur = new int[max + 1];
        int[] num = new int[max + 1];
        long[] sum = new long[max + 1];
        Arrays.fill(cur, 1);
        Arrays.fill(num, 1);
        Arrays.fill(sum, 1);
        for (int i = 2; i <= max; i++) {
            for (int j = i; j <= max; j += i) {
                int cnt = cntNum[i - 1] - cntNum[cur[j] - 1];
                sum[j] *= BigInteger.valueOf(num[j]).modPow(BigInteger.valueOf(cnt), bigMod).longValue();
                sum[j] %= mod;
                cur[j] = i;
                num[j]++;
                if (i == j) {
                    int cnt1 = cntNum[max] - cntNum[j - 1];
                    sum[j] *= BigInteger.valueOf(num[j]).modPow(BigInteger.valueOf(cnt1), bigMod).longValue() - BigInteger.valueOf(num[j] - 1).modPow(BigInteger.valueOf(cnt1), bigMod).longValue();
                    sum[j] %= mod;
                    ans += sum[j];
                    ans %= mod;
                }
            }
        }
        return ((ans % mod) + mod) % mod;
    }
}
