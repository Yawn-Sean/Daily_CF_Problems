import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/405/D">D. Toy Sum</a>
 * Author: nhant
 * 2025-04-03 21:29:19 +0800
 **/
public class D {
  static IO io;
  
  private static void solve() {
    final int S = 1000000;
    boolean[] has = new boolean[S + 1];
    int n = io.nextInt();
    int[] x = new int[n];
    for (int i = 0; i < n; i++) {
      x[i] = io.nextInt();
      has[x[i]] = true;
    }
    List<Integer> res = new ArrayList<>();
    for (int i = 0, y = 1; i < n; i++) {
      while (y <= S && (has[y] || has[S + 1 - y])) {
        y++;
      }
      if (!has[S + 1 - x[i]]) {
        res.add(S + 1 - x[i]);
      } else if (x[i] < S + 1 - x[i]) { // avoid processing again for x[i]'
        res.add(y);
        res.add(S + 1 - y);
        y++;
      }
    }
    io.println(res.size());
    for (int y : res) {
      io.printf("%d ", y);
    }
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
  }
}
