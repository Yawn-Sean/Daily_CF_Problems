import java.io.*;
import java.util.*;


public class test{
    private static void michael() throws IOException {
        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);

        int n = sc.nextInt();
        int ans;
        int mod = 1000000007;

        int sum0 = 0;
        int sum1 = 0;
        for(int i=1;i<=n;i++){
            if((i & 1) ==0){
                sum0 = (sum0 + sum1 + 1) % mod;
            }else{
                sum1 = (sum0 + sum1 + 1) % mod;
            }
        }
        ans = (sum0 + sum1) % mod;

        out.println(ans);
        out.close();
    }

    public static void main(String[] args) throws IOException {
        michael();
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