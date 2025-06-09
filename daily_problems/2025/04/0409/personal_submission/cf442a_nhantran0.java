import java.io.*;
import java.util.BitSet;
import java.util.StringTokenizer;

import static java.lang.Integer.bitCount;

/**
 * Refs: <a href="https://codeforces.com/problemset/problem/442/A">A. Borya and Hanabi</a>
 * <p>Author: nhant
 * <p>2025-04-10 03:12:02 +0800
 * <p>Submission: <a href="https://codeforces.com/problemset/submission/442/314807802">Apr/10/2025 04:09UTC+8</a>
 **/
public class A {
  static IO io;

  static int colorToIdx(char c) {
    return switch (c) {
      case 'R' -> 0;
      case 'G' -> 1;
      case 'B' -> 2;
      case 'Y' -> 3;
      case 'W' -> 4;
      default -> -1;
    };
  }
  
  private static void solve() {
    int n = io.nextInt();
    boolean[][] opt = new boolean[5][5];
    for (int i = 0; i < n; i++) {
      String s = io.next();
      int colorI = colorToIdx(s.charAt(0));
      int valI = s.charAt(1) - '1';
      opt[colorI][valI] = true;
    }
    BitSet b = new BitSet(1 << 10);
    int res = 25;
    for (int rowMask = 0, rowMaskEnd = (1 << 5); rowMask < rowMaskEnd; rowMask++) { // indicates which rows to reveal
      for (int colMask = 0, colMaskEnd = (1 << 5); colMask < colMaskEnd; colMask++) { // which cols to reveal
        boolean dup = false;
        b.clear();
        for (int r = 0; r < 5 && !dup; r++) {
          for (int c = 0; c < 5 && !dup; c++) {
            if (opt[r][c]) {
              int x = (rowMask & (1 << r)) + ((colMask & (1 << c)) << 5);
              if (b.get(x)) {
                dup = true;
              } else {
                b.set(x);
              }
            }
          }
        }
        if (!dup) res = Math.min(res, bitCount(rowMask) + bitCount(colMask));
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
    private final BufferedReader r;
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
