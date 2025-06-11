import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/813/C">C. The Tag Game</a>
 * <p>Author: nhant
 * <p>2025-04-16 15:27:25 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/813/315807605">Apr/16/2025 16:53UTC+8</a>
 **/
public class C {
  static IO io;

  static ArrayList<Integer>[] adj;
  static int[] da, db; // distance from Alice, Bob to all vertices

  static void dfs(int u, int p, int dist, int[] dists) {
    dists[u] = dist;
    for (int v : adj[u]) {
      if (v != p) {
        dfs(v, u, dist + 1, dists);
      }
    }
  }

  private static void solve() {
    int n = io.nextInt();
    int x = io.nextInt();
    x--;
    da = new int[n];
    db = new int[n];
    adj = new ArrayList[n];
    for (int i = 0; i < n; i++) adj[i] = new ArrayList<>();
    for (int i = 0; i < n - 1; i++) {
      int u = io.nextInt();
      int v = io.nextInt();
      u--;
      v--;
      adj[u].add(v);
      adj[v].add(u);
    }
    dfs(0, -1, 0, da);
    dfs(x, -1, 0, db);
    int res = 0;
    for (int i = 0; i < n; i++) {
      if (da[i] > db[i]) {
        res = Math.max(res, da[i] * 2);
      }
    }
    io.println(res);
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
