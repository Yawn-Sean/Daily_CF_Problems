import java.io.*;
import java.util.*;

public class cf1085d_lyongwolf {
    static void solve() {
        int n = sc.nextInt(), s = sc.nextInt();
        int[] d = new int[n + 1];
        for (int i = 1; i < n; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            d[u]++;
            d[v]++;
        }
        int cnt = 0;
        for (int v : d) {
            if (v == 1) {
                cnt++;
            }
        }
        out.println((double) s * 2 / cnt);
    }


    
    static boolean retest = false;
    static FastReader sc = new FastReader();
    static PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
    public static void main(String[] args) {
        if (retest) {int t = sc.nextInt(); while (t-- > 0) solve();} else solve(); out.flush(); out.close();
    }
    static class FastReader {
        BufferedReader r = new BufferedReader(new InputStreamReader(System.in)); 
        StringTokenizer st;
        String next() {
            try {while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine()); return st.nextToken();} 
            catch (Exception e) {return null;}
        }
        int nextInt() {return Integer.parseInt(next());}
        long nextLong() {return Long.parseLong(next());}
        double nextDouble() {return Double.parseDouble(next());}
    }
}