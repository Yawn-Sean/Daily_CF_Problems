import java.io.*;
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
        long m = sc.nextLong();
        long l = 0, r = 8 * m;
        while (l <= r) {
            long n = (l + r) / 2;
            long check = check(n);
            if (check >= m) r = n - 1;
            else l = n + 1;
        }
        long check = check(l);
        out.println(check == m ? l : -1);
    }

    private static long check(long n) {
        // check given that the maximum number is n, can we find m combinations
        long cnt = 0;
        for (long i = 2; i <= n; i++) {
            cnt += n / i / i / i;
            if (i * i * i > n) break;
        }
        return cnt;
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
