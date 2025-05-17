import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/780/C">C. Andryusha and Colored Balloons</a>
 * <p>Author: nhant
 * <p>2025-05-17 08:23:28 +0800
 * https://codeforces.com/problemset/submission/780/319956312
 **/
public class C {
  static IO io;

  static int[] colors;
  static ArrayList<Integer>[] g;

  static void dfs(int u, int p) {
    int c = 1;
    while (c == colors[u] || (p != -1 && c == colors[p])) {
      c++;
    }
    for (int v : g[u]) {
      if (v != p) {
        colors[v] = c++;
        while (c == colors[u] || (p != -1 && c == colors[p])) {
          c++;
        }
        dfs(v, u);
      }
    }
  }

  private static void solve() {
    int n = io.ni();
    colors = new int[n];
    g = new ArrayList[n];
    for (int i = 0; i < n; i++) {
      g[i] = new ArrayList<>();
    }
    int[] deg = new int[n];
    int maxDeg = 0;
    for (int i = 0; i < n - 1; i++) {
      int x = io.ni() - 1, y = io.ni() - 1;
      g[x].add(y);
      g[y].add(x);
      deg[x]++;
      deg[y]++;
      maxDeg = Math.max(maxDeg, Math.max(deg[x], deg[y]));
    }
    colors[0] = 1;
    dfs(0, -1);
    io.println(maxDeg + 1);
    for (int c : colors) {
      io.printf("%d ", c);
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
  
    public int ni() {
      return Integer.parseInt(next());
    }
  }
}
