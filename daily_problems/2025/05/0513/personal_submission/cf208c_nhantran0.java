import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/208/C">C. Police Station</a>
 * <p>Author: nhant
 * <p>2025-05-13 15:44:52 +0800
 * https://codeforces.com/problemset/submission/208/319489548, O(N + M)
 **/
public class C {
  static IO io;
  
  private static void solve() {
    int n = io.ni(), m = io.ni();
    ArrayList<Integer>[] adj = new ArrayList[n + 1];
    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<>();
    }
    for (int i = 0; i < m; i++) {
      int u = io.ni(), v = io.ni();
      adj[u].add(v);
      adj[v].add(u);
    }
    long[] f = new long[n + 1], g = new long[n + 1];
    int[] fd = new int[n + 1], gd = new int[n + 1];
    int DIST_MAX = 102;
    Arrays.fill(fd, DIST_MAX);
    Arrays.fill(gd, DIST_MAX);
    Queue<Integer> q = new ArrayDeque<>();
    q.add(1);
    fd[1] = 0;
    f[1] = 1;
    while (q.size() > 0) {
      int u = q.poll();
      for (int v : adj[u]) {
        if (fd[v] > fd[u] + 1) {
          fd[v] = fd[u] + 1;
          q.add(v);
        }
        if (fd[v] == fd[u] + 1) {
          f[v] += f[u];
        }
      }
    }
    q.add(n);
    gd[n] = 0;
    g[n] = 1;
    while (q.size() > 0) {
      int u = q.poll();
      for (int v : adj[u]) {
        if (gd[v] > gd[u] + 1) {
          gd[v] = gd[u] + 1;
          q.add(v);
        }
        if (gd[v] == gd[u] + 1) {
          g[v] += g[u];
        }
      }
    }
    double res = 1;
    for (int i = 2; i < n; i++) {
      if (fd[i] + gd[i] == fd[n]) {
        res = Math.max(res, f[i] * g[i] * (double) 2 / f[n]);
      }
    }
    io.printf("%.12f\n", res);
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
