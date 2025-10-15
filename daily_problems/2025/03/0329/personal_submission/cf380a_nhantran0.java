import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/380/A">A. Sereja and Prefixes</a>
 * Author: nhant
 * 2025-03-30 18:34:15 +0800
 **/
public class A {
  static IO io;
  // type=1: [op type, x, 0], type=2: [op type, l, c]
  private static int[][] ops;
  private static long[] len;

  private static void solve() {
    int m = io.nextInt();
    ops = new int[m][3];
    len = new long[m];
    for (int i = 0; i < m; i++) {
      int[] op = ops[i];
      op[0] = io.nextInt(); // t
      if (op[0] == 1) {
        op[1] = io.nextInt(); // x
        len[i] = (i > 0 ? len[i - 1] : 0) + 1;
      } else { // t == 2
        op[1] = io.nextInt(); // l
        op[2] = io.nextInt(); // c
        len[i] = len[i - 1] + (long) op[1] * op[2];
      }
    }
    int n = io.nextInt();
    for (int i = 0; i < n; i++) {
      long p = io.nextLong();
      int x = find(p, len.length);
      io.printf(i == 0 ? "%d" : " %d", x);
    }
  }

  // hi: (first true) first index i of len entry where p <= len[i]
  private static int find(long p, int hi) {
    // finding first len[i] where p <= len[i]
    int lo = 0;
    while (lo < hi) {
      int mi = (lo + hi) / 2;
      if (p <= len[mi]) {
        hi = mi;
      } else {
        lo = mi + 1;
      }
    }
    if (ops[hi][0] == 1) return ops[hi][1];
    return find((p - len[hi - 1] - 1) % ops[hi][1] + 1, hi);
  }
  
  public static void main(String[] args) {
    io = new IO();
    solve();
    io.close();
  }
  
  static class IO extends PrintWriter {
    private BufferedReader r;
    private StringTokenizer st;
  
    public IO() {
      this(System.in, System.out);
    }
  
    public IO(InputStream i, OutputStream o) {
      super(o);
      r = new BufferedReader(new InputStreamReader(i), 1 << 15);
    }
    
    public String next() {
      try {
        while (st == null || !st.hasMoreTokens()) st = new StringTokenizer(r.readLine());
        return st.nextToken();
      } catch (Exception e) {
      }
      return null;
    }
  
    public int nextInt() {
      return Integer.parseInt(next());
    }

    public long nextLong() {
      return Long.parseLong(next());
    }
  }
}
