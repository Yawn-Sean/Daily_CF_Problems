import java.io.*;
import java.util.Stack;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/911/E">E. Stack Sorting</a>
 * Author: nhant
 * 2025-04-03 22:02:33 +0800
 **/
public class E {
  static IO io;
  
  private static void solve() {
    int n = io.nextInt();
    int k = io.nextInt();
    int[] p = new int[n];
    boolean[] has = new boolean[n + 1];
    for (int i = 0; i < k; i++) {
      p[i] = io.nextInt();
      has[p[i]] = true;
    }
    Stack<Integer> st = new Stack<>();
    int bNext = 1;
    int i = 0;
    while (i < k) {
      int opCnt = 0;
      while (!st.isEmpty() && st.peek() == bNext) {
        bNext++;
        st.pop();
        opCnt++;
      }
      while (st.isEmpty() || (i < k && p[i] < st.peek())) {
        st.push(p[i++]);
        opCnt++;
      }
      if (opCnt == 0) break;
    }
    if (i < k) {
      io.println(-1);
      return;
    }
    while (!st.isEmpty()) {
      int x = st.pop();
      while (x > 1 && !has[x - 1]) {
        p[i++] = --x;
      }
    }
    for (int v = n; i < n; v--, i++) {
      p[i] = v;
    }
    for (int x : p)
      io.printf("%d ", x);
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
  
    public int nextInt() {
      return Integer.parseInt(next());
    }
  }
}
