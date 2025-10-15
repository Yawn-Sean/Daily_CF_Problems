import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1835/A">A. k-th equality</a>
 * <p>Author: nhant
 * <p>2025-04-17 19:43:08 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/1835/315984125">Apr/17/2025 23:48UTC+8</a>
 **/
public class A {
  static IO io;

  static int minOfCnt(int d) {
    int x = 1;
    while (d > 1) {
      d--;
      x *= 10;
    }
    return x;
  }

  static int maxOfCnt(int d) {
    int x = 1;
    while (d > 0) {
      d--;
      x *= 10;
    }
    return x - 1;
  }
  
  private static void solve() {
    int A = io.nextInt();
    int B = io.nextInt();
    int C = io.nextInt();
    long k = io.nextLong();
    if (Math.max(A, B) > C || Math.max(A, B) + 1 < C) {
      io.println(-1);
      return;
    }
    int aMin = minOfCnt(A), aMax = maxOfCnt(A);
    int bMin = minOfCnt(B), bMax = maxOfCnt(B);
    int cMin = minOfCnt(C), cMax = maxOfCnt(C);
    boolean solved = false;
    for (int a = aMin; a <= aMax && k > 0; a++) {
      // find overlap of 2 intervals
      int cl = Math.max(a + bMin, cMin), cr = Math.min(a + bMax, cMax);
      if (cl <= cr) {
        long d = Math.min(k, cr - cl + 1);
        k -= d;
        if (k == 0) {
          solved = true;
          int c = cl - 1 + (int) d;
          io.printf("%d + %d = %d\n", a, c - a, c);
          break;
        }
      }
    }
    if (!solved) io.println(-1);
  }
  
  public static void main(String[] args) {
    try {
      io = new IO();
      int tc = io.nextInt();
      while (tc-- > 0) {
        solve();
      }
    } finally {
      io.close();
    }
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
