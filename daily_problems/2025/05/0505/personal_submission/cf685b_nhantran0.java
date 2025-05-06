import java.io.*;
import java.util.ArrayList;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/685/B">B. Kay and Snowflake</a>
 * <p>Author: nhant
 * <p>2025-05-06 08:50:14 +0800
 * https://codeforces.com/problemset/submission/685/318568577
 **/
public class B {
  static IO io;

  static ArrayList<Integer>[] child;
  static int[] size, centroid, pa;

  static void dfs(int u) {
    int treeSize = 1, maxChildSize = 0, maxChild = 0;
    for (int v : child[u]) {
      dfs(v);
      treeSize += size[v];
      if (size[v] > maxChildSize) {
        maxChildSize = size[v];
        maxChild = v;
      }
    }
    if (maxChild == 0) {
      centroid[u] = u;
    } else {
      int c = centroid[maxChild];
      while (c != u && size[c] * 2 < treeSize) {
        c = pa[c];
      }
      centroid[u] = c;
    }
    size[u] = treeSize;
  }

  private static void solve() {
    int n = io.ni(), q = io.ni();
    child = new ArrayList[n + 1];
    size = new int[n + 1];
    centroid = new int[n + 1];
    pa = new int[n + 1];
    for (int i = 0; i <= n; i++) {
      if (i > 0) {
        child[i] = new ArrayList<>();
        size[i] = 1;
      }
    }
    for (int i = 2; i <= n; i++) {
      int p = io.ni();
      pa[i] = p;
      child[p].add(i);
    }
    dfs(1);
    while (q-- > 0) {
      int v = io.ni();
      io.println(centroid[v]);
    }
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
