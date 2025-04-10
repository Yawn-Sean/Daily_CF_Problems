import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/29/D">D. Ant on the Tree</a>
 * <p>Author: nhant
 * <p>2025-04-10 04:33:44 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/29/314812300">Apr/10/2025 05:25UTC+8</a>
 **/
public class D {
  static IO io;

  static int ROOT = 1;
  static ArrayList<Integer>[] adj;
  static BitSet[] leaves;
  static boolean[] visited;
  static int[] leafOrd;
  static int nextLeafI;
  static List<Integer> path;

  static void dfs1(int u, int p) {
    if (adj[u].size() == 1 && u != ROOT) {
      leaves[u].set(u);
    }
    for (int v : adj[u]) {
      if (v != p) {
        dfs1(v, u);
        leaves[u].or(leaves[v]);
      }
    }
  }

  static void dfs2(int u, int p) {
    if (nextLeafI == -1) return;
    visited[u] = true;
    path.add(u);
    if (adj[u].size() == 1 && u != ROOT) {
      if (leaves[u].get(leafOrd[nextLeafI])) {
        nextLeafI++;
      } else {
        nextLeafI = -1;
      }
      return;
    }
    boolean explored = true;
    while (explored) {
      explored = false;
      for (int v : adj[u]) {
        if (v != p && !visited[v] && leaves[v].get(leafOrd[nextLeafI])) {
          explored = true;
          dfs2(v, u);
          path.add(u);
        }
      }
    }
  }
  
  private static void solve() {
    int n = io.nextInt();
    adj = new ArrayList[n + 1];
    leaves = new BitSet[n + 1];
    for (int i = 1; i <= n; i++) {
      adj[i] = new ArrayList<>();
      leaves[i] = new BitSet(301);
    }
    for (int i = 0; i < n - 1; i++) {
      int u = io.nextInt(), v = io.nextInt();
      adj[u].add(v);
      adj[v].add(u);
    }
    dfs1(1, -1);
    int k = leaves[1].cardinality();
    leafOrd = new int[k];
    for (int i = 0; i < k; i++) {
      leafOrd[i] = io.nextInt();
    }
    visited = new boolean[n + 1];
    nextLeafI = 0;
    path = new ArrayList<>();
    dfs2(1, -1);
    if (nextLeafI != k) {
      io.println(-1);
    } else {
      for (int v : path)
        io.printf("%d ", v);
      io.println();
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
