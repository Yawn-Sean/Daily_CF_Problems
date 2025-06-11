import java.io.*;
import java.util.*;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/1090/K">K. Right Expansion Of The Mind</a>
 * Author: nhant
 * 2025-04-03 06:54:26 +0800
 **/
public class K {
  static IO io;

  private static int createMask(String t) {
    int x = 0;
    for (int i = 0; i < t.length(); i++) {
      x |= (1 << (t.charAt(i) - 'a'));
    }
    return x;
  }

  private static boolean maskHasChar(int mask, char c) {
    return (mask & (1 << (c - 'a'))) != 0;
  }

  private static void solve() {
    int n = io.nextInt();
    Map<Key, List<Integer>> mp = new HashMap<>();
    for (int i = 0; i < n; i++) {
      String w = io.next();
      String t = io.next();
      int mask = createMask(t);
      int len = w.length();
      while (len > 0 && maskHasChar(mask, w.charAt(len - 1))) {
        len--;
      }
      String w2 = w.substring(0, len);
      Key key = new Key(w2, mask);
      List<Integer> indices;
      if (!mp.containsKey(key)) {
        indices = new ArrayList<>();
        indices.add(i + 1);
        mp.put(key, indices);
      } else {
        indices = mp.get(key);
        indices.add(i + 1);
      }
    }
    io.println(mp.size());
    for (Map.Entry<Key, List<Integer>> entry : mp.entrySet()) {
      io.print(entry.getValue().size());
      for (Integer x : entry.getValue()) {
        io.printf(" %d", x);
      }
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

  static class Key {
    String w;
    int mask;

    public Key(String w, int mask) {
      this.w = w;
      this.mask = mask;
    }

    @Override
    public boolean equals(Object o) {
      if (o == null || getClass() != o.getClass()) return false;
      Key key = (Key) o;
      return mask == key.mask && Objects.equals(w, key.w);
    }

    @Override
    public int hashCode() {
      return Objects.hash(w, mask);
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
