//happy new year
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class D105805 {
    static class FenwickTree {
        long[] bit;
        int n;

        public FenwickTree(int n) {
            this.n = n;
            this.bit = new long[n];
        }

        public void add(int i, long delta) {
            while (i < n) {
                bit[i] += delta;
                i |= i + 1;
            }
        }

        // Sum [0, i] 
        public long sum(int i) {
            long s = 0;
            while (i >= 0) {
                s += bit[i];
                i = (i & (i + 1)) - 1;
            }
            return s;
        }

        // [l, r)
        public long sum(int l, int r) {
            if (l >= r) return 0;
            long res = sum(r - 1);
            if (l > 0) res -= sum(l - 1);
            return res;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        Scanner sc=new Scanner(System.in);
        int t = sc.nextInt();

        while (t-- > 0) {
            int n = sc.nextInt();

            FenwickTree fen = new FenwickTree(n + 1); // indices 0 to n

            long cur = 0;
            List<Long> diff = new ArrayList<>();

            for (int i = 0; i < n; i++) {
                int v = sc.nextInt();
                long v1 = fen.sum(v + 1, n + 1);
                long v2 = fen.sum(0, v);
                cur += v1;
                diff.add(v2 - v1);

                fen.add(v, 1);
            }

            Collections.sort(diff);

            StringBuilder sb = new StringBuilder();
            sb.append(cur);
            for (long x : diff) {
                cur += x;
                sb.append(' ').append(cur);
            }
            pw.println(sb.toString());
        }
        sc.close();
        pw.flush();
        pw.close();
        br.close();
    }
}
