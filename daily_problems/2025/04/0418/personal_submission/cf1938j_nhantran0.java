import java.io.*;
import java.util.ArrayList;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/contest/1938/problem/J">J. There and Back Again</a>
 * <p>Author: nhant
 * <p>2025-04-19 04:16:51 +0800
 * <p>Submission: <a href="https://codeforces.com/contest/1938/submission/316152710">Apr/19/2025 05:06UTC+8</a>
 **/
public class J {
  static IO io;
  static ArrayList<int[]>[] adj;
  static int[] prev;

  static void dijkstra(int src, int[] d, boolean savePath) {
    PriorityQueue<int[]> q = new PriorityQueue<>((u, v) -> u[1] - v[1]);
    d[src] = 0;
    q.offer(new int[]{src, 0});
    while (!q.isEmpty()) {
      int[] au = q.poll();
      int u = au[0], ut = au[1];
      if (ut > d[u]) continue;
      for (int[] av : adj[u]) {
        int v = av[0], vt = av[1];
        if (d[v] > d[u] + vt) {
          d[v] = d[u] + vt;
          q.offer(new int[]{v, d[v]});
          if (savePath) prev[v] = u;
        }
      }
    }
  }

  private static void solve() {
    final int MAX_DIST = (int) 1e9;
    int n = io.nextInt();
    int m = io.nextInt();
    adj = new ArrayList[n];
    int[] d1 = new int[n], dn = new int[n];
    prev = new int[n];
    int[] next = new int[n]; // mark used edge by storing next vertex in 1st route 1->n
    for (int i = 0; i < n; i++) {
      adj[i] = new ArrayList<>();
      d1[i] = dn[i] = MAX_DIST;
      prev[i] = -1;
      next[i] = -1;
    }
    int[][] edges = new int[m][3];
    for (int i = 0; i < m; i++) {
      int u = io.nextInt() - 1;
      int v = io.nextInt() - 1;
      int t = io.nextInt();
      adj[u].add(new int[]{v, t});
      adj[v].add(new int[]{u, t});
      edges[i] = new int[]{u, v, t};
    }
    dijkstra(0, d1, true);
    int cur = n - 1;
    while (prev[cur] != -1) {
      int u = prev[cur];
      next[u] = cur;
      cur = u;
    }
    dijkstra(n - 1, dn, false);
    int res = MAX_DIST;
    for (int i = 0; i < m; i++) {
      int u = edges[i][0], v = edges[i][1], t = edges[i][2];
      if (next[u] != v && next[v] != u) {
        if (d1[u] != MAX_DIST && dn[v] != MAX_DIST) {
          res = Math.min(res, d1[n - 1] + d1[u] + dn[v] + t);
        }
        if (d1[v] != MAX_DIST && dn[u] != MAX_DIST) {
          res = Math.min(res, d1[n - 1] + d1[v] + dn[u] + t);
        }
      }
    }
    io.println(res != MAX_DIST ? res : -1);
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
