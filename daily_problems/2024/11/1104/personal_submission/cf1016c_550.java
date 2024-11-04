import java.io.*;
import java.util.*;

public class Main {
    static MyScanner sc = new MyScanner();
    public static PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
    public static void main(String[] args) {
        int t = 1;
        while (t-- > 0) {
            solve();
        }
        out.close();
    }

    private static void solve() {
        int n = sc.nextInt();
        long[][] arr = new long[2][n];
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) {
                arr[i][j] = sc.nextInt();
            }
        }
        // 分为两种行走方法 
        // 1. 上下蛇皮走位
        // 2. 绕圈，从下绕到上，以及从上绕到下
        // 前缀和处理从上圈到下圈，以及从下圈到上圈的前缀和
        long[] b1 = new long[2 * n + 1];
        long[] b2 = new long[2 * n + 1];
        long[] w1 = new long[2 * n + 1];
        long[] w2 = new long[2 * n + 1];
        for (int i = 0; i < n; i++) {
            b1[i + 1] = b1[i] + arr[0][i];
            w1[i + 1] = w1[i] + (i + 2 * n) * arr[0][i];
            b2[i + 1] = b2[i] + arr[1][i];
            w2[i + 1] = w2[i] + (i + 2 * n) * arr[1][i];
        }
        for (int i = n; i < 2 * n; i++) {
            b1[i + 1] = b1[i] + arr[1][n - 1 - i % n];
            w1[i + 1] = w1[i] + (i + 2 * n) * arr[1][n - 1 - i % n];
            b2[i + 1] = b2[i] + arr[0][n - 1- i % n];
            w2[i + 1] = w2[i] + (i + 2 * n) * arr[0][n - 1 - i % n];
        }
        long max = 0;
        int curr = 0;
        // 当前蛇皮走位的总值
        long last = 0;
        for (int j = 0; j < n; j++) {
            // 该列的第一步
            if (curr == 0) {
                long b = b1[2 * n - j] - b1[j];
                long w = w1[2 * n - j] - w1[j];
                long v = w - b * (2 * n - j);
                max = Math.max(v + last, max);
            } else {
                // 下到上的圈
                long b = b2[2 * n - j] - b2[j];
                long w = w2[2 * n - j] - w2[j];
                long v = w - b * (2 * n - j);
                max = Math.max(v + last, max);
            }
            last += 2 * j * arr[curr][j];
            curr = 1 - curr;
            last += (2L * j + 1) * arr[curr][j];
            // 该列的第二步
            if (curr == 0) {
                // 上到下的圈
                long b = b1[2 * n - j - 1] - b1[j + 1];
                long w = w1[2 * n - j - 1] - w1[j + 1];
                int d = 2 * n + j - (2 * j + 1);
                long v = w - b * d;
                max = Math.max(v + last, max);
            } else {
                // 下到上的圈
                long b = b2[2 * n - j - 1] - b2[j + 1];
                long w = w2[2 * n - j - 1] - w2[j + 1];
                int d = 2 * n + j - (2 * j + 1);
                long v = w - b * d;
                max = Math.max(v + last, max);
            }
        }
        out.println(max);
    }

    //-----------PrintWriter for faster output---------------------------------


    //-----------MyScanner class for faster input----------
    public static class MyScanner {
        BufferedReader br;
        StringTokenizer st;

        public MyScanner() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreElements()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }

        long nextLong() {
            return Long.parseLong(next());
        }

        double nextDouble() {
            return Double.parseDouble(next());
        }

        String nextLine(){
            String str = "";
            try {
                str = br.readLine();
            } catch (IOException e) {
                e.printStackTrace();
            }
            return str;
        }

    }
}
