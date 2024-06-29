import java.util.*;
import java.io.*;

public class Main {

    static int[] val = {'R', 'G', 'B'};
    static int[][] op = {{0, 1, 2}, {1, 2, 0}, {2, 0, 1}};

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        char[] str = sc.next().toCharArray();
        int[][][] sum = new int[3][3][n + 1];
        for (int i = 0; i < n; i++) {
            int t = i % 3;
            for (int j = 0; j < 3; j++) {
                for (int s = 0; s < 3; s++) {
                    sum[j][s][i + 1] = sum[j][s][i] + (t == j && val[s] == str[i] ? 1 : 0);
                }
            }
        }
        int ans = n;
        for (int i = 0, j = k - 1; j < n; i++, j++) {
            for (int[] p : op) {
                int cnt = 0;
                for (int s = 0, t = i; s < 3 && t <= j; s++, t++) {
                    cnt += (j - t) / 3 + 1 - (sum[t % 3][p[s]][j + 1] - sum[t % 3][p[s]][i]);
                }
                ans = Math.min(ans, cnt);
            }
        }
        out.println(ans);
    }
   
    
    static boolean retest = true;
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
