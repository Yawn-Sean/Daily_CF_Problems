import java.io.*;
import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/234/H">H. Merging Two Decks</a>
 * <p>Author: nhant
 * <p>2025-04-25 00:52:28 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/234/317087631">Apr/25/2025 01:56UTC+8, 936 ms, 2000 KB</a>
 **/
public class H {
  static IO io;

  private static void solve() {
    int n = io.nextInt();
    int[] a = new int[n];
    int alast1 = 0, blast1 = n; // blast1 is offset as well
    for (int i = 0; i < n; i++) {
      int x = io.nextInt();
      a[i] = x == 1 ? i + 1 : -i - 1;
      if (x == 1) alast1 = a[i];
    }
    int m = io.nextInt();
    int[] b = new int[m];
    for (int i = 0; i < m; i++) {
      int x = io.nextInt();
      b[i] = x == 1 ? n + i + 1 : -n - i - 1;
      if (x == 1) blast1 = b[i];
    }
    int[] c = new int[n + m];
    int i = 0;
    for (; i < n - alast1; i++) {
      c[n + m - i - 1] = a[n - 1 - i];
    }
    for (int j = 0; j < m + n - blast1; i++, j++) {
      c[n + m - i - 1] = b[m - 1 - j];
    }
    int len0 = i, ai = alast1 - 1, bi = blast1 - n - 1;
    boolean pos = true;
    while (i < n + m) {
      while (ai >= 0 && (pos && a[ai] > 0 || (!pos && a[ai] < 0))) {
        c[n + m - i - 1] = a[ai--];
        i++;
      }
      while (bi >= 0 && (pos && b[bi] > 0 || (!pos && b[bi] < 0))) {
        c[n + m - i - 1] = b[bi--];
        i++;
      }
      pos = !pos;
    }
    for (int x : c) io.printf("%d ", Math.abs(x));
    io.println();
    List<Integer> ops = new ArrayList<>();
    for (i = 1; i < n + m - len0; i++) {
      if (c[i - 1] > 0 && c[i] < 0 || (c[i - 1] < 0 && c[i] > 0)) ops.add(i);
    }
    if (len0 < n + m) ops.add(n + m - len0);
    io.println(ops.size());
    for (int x : ops) io.printf("%d ", x);
    if (!ops.isEmpty()) io.println();
  }

  public static void main(String[] args) {
    try {
//      io = new IO();
      io = new IO("input.txt", "output.txt");
      solve();
    } catch (FileNotFoundException e) {
      throw new RuntimeException(e);
    } finally {
      if (io != null)
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

    public IO(String i, String o) throws FileNotFoundException {
      this(new FileInputStream(i), new FileOutputStream(o));
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
