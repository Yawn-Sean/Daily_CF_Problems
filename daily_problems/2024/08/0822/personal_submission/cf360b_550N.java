
import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

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
        int n = sc.nextInt(), k = sc.nextInt();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) arr[i] = sc.nextInt();
        if (n == 1 || k + 1 >= n) {
            out.println(0);
            return;
        }
        long l = 0, r = (int) (2e9);
        while (l <= r) {
            long m = (l + r) / 2;
            if (check(arr, m, k)) r = m - 1;
            else l = m + 1;
        }
        out.println(l);
    }

    private static boolean check(long[] arr, long m, int k) {
        int[] dp = new int[arr.length];
        Arrays.fill(dp, 1);
        for (int i = 1; i < arr.length; i++) {
            for (int j = 0; j < i; j++) {
                if (Math.abs(arr[i] - arr[j]) <= (i - j) * m) {
                    dp[i] = Math.max(dp[j] + 1, dp[i]);
                }
            }
        }
        for (int i = 0; i < dp.length; i++) {
            // 前面用了多少次操作
            int used = i + 1 - dp[i], left = k - used;
            if (left >= dp.length - i - 1) return true;
        }
        return false;
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
