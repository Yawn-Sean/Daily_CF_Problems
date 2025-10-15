import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1530/D">D. Secret Santa</a>
 * Author: nhant
 * 2025-04-04 21:47:45 +0800
 **/
public class D {
  static IO io;

  private static void solve() {
    int n = io.nextInt();
    int[] b = new int[n + 1];
    List<List<Integer>> from = new ArrayList<>(n + 1);
    for (int i = 0; i <= n; i++) from.add(new ArrayList<>());
    for (int i = 1; i <= n; i++) {
      b[i] = io.nextInt();
      from.get(b[i]).add(i);
    }
    int k = n;
    for (int i = 1; i <= n; i++) {
      if (from.get(i).size() > 1) {
        List<Integer> vts = from.get(i);
        boolean sawKeep = false;
        for (int j = 0, m = vts.size(); j < m; j++) {
          int u = vts.get(j);
          // prioritize breaking edges of a "path" to create at least 1 path (from a circle) or 2 paths (from a path)
          if (!sawKeep && (from.get(u).isEmpty() || j == m - 1)) {
            sawKeep = true;
          } else {
            b[u] = 0;
            k--;
          }
        }
      }
    }
    List<int[]> paths = new ArrayList<>();
    for (int i = 1; i <= n; i++) {
      if (from.get(i).isEmpty()) {
        int end = i;
        while (b[end] != 0) end = b[end];
        paths.add(new int[]{i, end});
      }
    }
    for (int i = 0; i < paths.size(); i++) {
      int j = i == paths.size() - 1 ? 0 : i + 1;
      b[paths.get(i)[1]] = paths.get(j)[0];
    }
    io.println(k);
    for (int i = 1; i <= n; i++)
      io.printf("%d ", b[i]);
    io.println();
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
  }
}
