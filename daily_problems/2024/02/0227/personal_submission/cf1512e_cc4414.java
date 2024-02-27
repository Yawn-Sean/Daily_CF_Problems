import java.io.*;
import java.util.StringTokenizer;

public class Main {
    public static void main(String[] args) {
        InputReader in = new InputReader(System.in);
        PrintWriter out = new PrintWriter(System.out);
        Task solver = new Task();
        solver.solve(in.nextInt(), in, out);
        out.close();
    }

    static class Task {
        public void solve(int testNumber, InputReader in, PrintWriter out) {
            for (int t = 0; t < testNumber; t++) {
                int[] solve = new Solution().solve(in.nextInt(), in.nextInt() - 1, in.nextInt() - 1, in.nextInt());
                if (solve == null) {
                    out.println(-1);
                } else {
                    for (int v : solve) {
                        out.print(v + " ");
                    }
                    out.println();
                }
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
    public int[] solve(int n, int l, int r, int s) {
        // 子数组长度
        int len = r - l + 1;
        // 最小值
        int min = (1 + len) * len / 2;
        // 最大值
        int max = (n - len + 1 + n) * len / 2;
        if (s < min || s > max) {
            return null;
        }
        // 子数组从最小值开始逐个加1，直到和等于s为止
        int[] arr = new int[len];
        int sum = 0;
        for (int i = 0; i < arr.length; i++) {
            arr[i] = i + 1;
            sum += arr[i];
        }
        // 从后往前逐个加1
        int j = len - 1;
        for (int i = sum; i < s; i++) {
            arr[j]++;
            j--;
            if (j < 0) {
                j += len;
            }
        }
        // 构造最终答案
        int[] ans = new int[n];
        boolean[] vis = new boolean[n + 1];
        for (int i = 0; i < len; i++) {
            ans[i + l] = arr[i];
            vis[arr[i]] = true;
        }
        j = 1;
        for (int i = 0; i < n; i++) {
            if (i >= l && i <= r) {
                continue;
            }
            while (j < n + 1 && vis[j]) {
                j++;
            }
            ans[i] = j;
            j++;
        }
        return ans;
    }
}