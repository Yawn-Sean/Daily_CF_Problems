import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Main {
    public static int mod = (int)1e9 + 7;
    public static int[] dp = new int[(int)3e5 + 5];
    public static void solve(){
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(new OutputStreamWriter(System.out));

        int t = sc.nextInt();
        while(t-- > 0){
            int n = sc.nextInt();
            int k = sc.nextInt();
            for(int i = 0;i < k;i++){
                int r = sc.nextInt();
                int c = sc.nextInt();
                n -= r == c ? 1 : 2;
            }
            dp[0] = dp[1] = 1;
            for(int i = 2;i <= n;i++){
                dp[i] = ( dp[i - 1] + (int)(2L * (i - 1) * dp[i - 2] % mod) ) % mod;
            }
            out.println(dp[n]);
        }

        out.flush();
        out.close();
    }

    public static void main(String[] args) {
        solve();
    }

    static class FastReader {
        BufferedReader br;
        StringTokenizer st;

        public FastReader() {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try { st = new StringTokenizer(br.readLine()); }
                catch (IOException e) { e.printStackTrace(); }
            }
            return st.nextToken();
        }

        int nextInt() { return Integer.parseInt(next()); }
        long nextLong() { return Long.parseLong(next()); }
        double nextDouble() { return Double.parseDouble(next()); }
        String nextLine() {
            String str = "";
            try { str = br.readLine(); }
            catch (IOException e) { e.printStackTrace(); }
            return str;
        }
    }
}
