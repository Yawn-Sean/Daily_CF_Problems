import java.io.*;
import java.util.*;

public class a{
    private static void michael(){

        FastReader sc = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        long n = sc.nextLong();
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();
        long ans = 0;
        if(b <= n && b - c <= a){
            ans += (n - b) / (b - c) + 1;
            n -= (ans - 1) * (b - c);
            n -= b - c;
        }

        ans += n / a ;

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