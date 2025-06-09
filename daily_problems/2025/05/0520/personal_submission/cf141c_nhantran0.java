import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/141/C">C. Queue</a>
 * <p>Author: nhant
 * <p>2025-05-21 06:49:27 +0800
 * https://codeforces.com/problemset/submission/141/320577394, 622 ms
 **/
public class C {
  IO io;
  
  void solve() {
    int n = io.ni();
    String[] s = new String[n];
    Integer[] ord = new Integer[n];
    int[] a = new int[n], h = new int[n];
    for (int i = 0; i < n; i++) {
      s[i] = io.next();
      a[i] = io.ni();
      ord[i] = i;
    }
    Arrays.sort(ord, (i, j) -> a[i] - a[j]);

    int[] res = new int[n];
    Arrays.fill(res, -1);
    for (int i = n - 1, curH = 1; i >= 0; i--, curH++) {
      while (i > 0 && a[ord[i - 1]] == a[ord[i]]) {
        i--;
      }
      if (a[ord[i]] > i) {
        io.println(-1);
        return;
      }
      res[a[ord[i]]] = ord[i];
      h[ord[i]] = curH;
      for (int j = i + 1, k = a[ord[i]] + 1; j < n && a[ord[j]] == a[ord[i]]; j++) {
        while (res[k] != -1) {
          k++;
        }
        res[k] = ord[j];
        h[ord[j]] = curH;
      }
    }
    for (int i = 0; i < n; i++) {
      io.printf("%s %d\n", s[res[i]], h[res[i]]);
    }
  }
  
  void run() {
    try {
      io = new IO();
      solve();
    } finally {
      io.close();
    }
  }
  
  public static void main(String[] args) {
    (new C()).run();
  }
  
  static class IO extends PrintWriter {
    final private BufferedReader r;
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
      } catch (Exception ignored) {
      }
      return null;
    }
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
