import java.io.*;
import java.util.*;
import java.util.function.Function;

import static java.lang.Math.max;
import static java.lang.Math.min;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1915/G">G. Bicycles</a>
 * <p>Author: nhant
 * <p>2025-05-20 09:22:37 +0800
 * https://codeforces.com/problemset/submission/1915/320446203
 **/
public class G {
  IO io;
  
  void solve() {
    int n = io.ni(), m = io.ni();
    List<List<int[]>> g = new ArrayList<>(n + 1);
    for (int i = 0; i <= n; i++) g.add(new ArrayList<>());

    for (int i = 0; i < m; i++) {
      int u = io.ni(), v = io.ni(), w = io.ni();
      g.get(u).add(new int[]{v, w});
      g.get(v).add(new int[]{u, w});
    }

    int maxS = 0;
    int[] s = new int[n + 1];
    for (int i = 1; i <= n; i++) {
      s[i] = io.ni();
      maxS = max(maxS, s[i]);
    }

    long MAX_TIME = (long)1e12;
    final int MAX_S = maxS;
    long[][] t = new long[n + 1][MAX_S + 1];
    for (int i = 1; i <= n; i++) {
      Arrays.fill(t[i], MAX_TIME);
    }

    Function<int[], Long> pri = (int[] a) -> t[a[0]][a[1]] * (MAX_S + 1) + a[1];
    PriorityQueue<int[]> q = new PriorityQueue<>((a, b) -> Long.compare(pri.apply(a), pri.apply(b)));
    t[1][s[1]] = 0;
    q.add(new int[]{1, s[1]});

    while (!q.isEmpty()) {
      int[] a = q.poll();
      int u = a[0], us = a[1];

      for (int[] b : g.get(u)) {
        int v = b[0], w = b[1], ns = min(us, s[v]);

        if (t[v][ns] > t[u][us] + (long) us * w) {
          t[v][ns] = t[u][us] + (long) us * w;
          q.add(new int[]{v, ns});
        }
      }
    }

    long res = MAX_TIME;
    for (long tr : t[n]) {
      res = min(res, tr);
    }
    io.println(res);
  }
  
  void run() {
    try {
      io = new IO();
      int tc = io.ni();
      while (tc-- > 0) {
        solve();
      }
    } finally {
      io.close();
    }
  }
  
  public static void main(String[] args) {
    (new G()).run();
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
