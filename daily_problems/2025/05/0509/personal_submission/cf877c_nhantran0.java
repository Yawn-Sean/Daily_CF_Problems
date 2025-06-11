import java.io.*;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/877/C">C. Slava and tanks</a>
 * <p>Author: nhant
 * <p>2025-05-10 04:13:30 +0800
 * https://codeforces.com/problemset/submission/877/318987305
 **/
public class C {
  static IO io;

  static void printAlter(int n, int start) {
    for (int i = start; i <= n; i += 2) {
      io.printf("%d ", i);
    }
  }
  
  private static void solve() {
    int m = io.ni();
    int r = (m / 2) * 2 + (m + 1) / 2;
    io.println(r);
    printAlter(m, 2);
    printAlter(m, 1);
    printAlter(m, 2);
    io.println();
  }
  
  public static void main(String[] args) {
    try {
      io = new IO();
      solve();
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
      super(o, true);
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
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
