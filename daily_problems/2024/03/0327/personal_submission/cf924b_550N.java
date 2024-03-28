import java.io.*;
import java.util.StringTokenizer;

// If AtCoder, change className to Main
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
        int n = sc.nextInt(), u = sc.nextInt();
        double[] es = new double[n];
        for (int i = 0; i < n; i++) es[i] = sc.nextDouble();
        //
        double res = -1;
        for (int i = 0; i < n - 2; i++) {
            double ival = es[i] + u;
            // 找到最后一个比ival大的k
            int l = i + 1, r = n - 1;
            if (es[i+2] > ival) continue;
            while (l <= r) {
                int m = (l + r) / 2;
                if (es[m] <= ival) l = m + 1;
                else r = m - 1;
            }
            res = Math.max(res, (es[l - 1] - es[i + 1]) / (es[l - 1] - es[i]));
        }
        out.println(res);
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
