import java.io.*;
import java.util.PriorityQueue;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/689/B">B. Mike and Shortcuts</a>
 * <p>Author: nhant
 * <p>2025-05-10 17:20:36 +0800
 * https://codeforces.com/problemset/submission/689/319049555
 **/
public class B {
  static IO io;

  private static void solve() {
    final int MAX_ENERGY = (int)1e9;
    final int[] dirs = new int[]{-1, 1};
    int n = io.ni();
    int[] a = new int[n + 2];
    int[] en = new int[n + 2];
    for (int i = 1; i <= n; i++) {
      a[i] = io.ni();
      en[i] = MAX_ENERGY;
    }
    en[1] = 0;
    PriorityQueue<Integer> q = new PriorityQueue<>((i, j) -> en[i] - en[j]);
    q.add(1);
    while (q.size() > 0) {
      int u = q.poll();
      if (a[u] != u && en[a[u]] > en[u] + 1) {
        en[a[u]] = en[u] + 1;
        q.add(a[u]);
      }
      for (int d : dirs) {
        int v = u + d;
        if (v >= 1 && v <= n && en[v] > en[u] + 1) {
          en[v] = en[u] + 1;
          q.add(v);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      io.printf("%d ", en[i]);
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
