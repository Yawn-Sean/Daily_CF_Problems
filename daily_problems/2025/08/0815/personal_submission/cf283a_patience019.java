import java.io.*;
import java.util.*;

public class Main {
    // 快速输入
    static class FastScanner {
        private final InputStream in;
        private final byte[] buffer = new byte[1 << 16];
        private int ptr = 0, len = 0;

        FastScanner(InputStream is) {
            in = is;
        }

        private int read() throws IOException {
            if (ptr >= len) {
                len = in.read(buffer);
                ptr = 0;
                if (len <= 0) return -1;
            }
            return buffer[ptr++];
        }

        int nextInt() throws IOException {
            int c, sgn = 1, x = 0;
            do {
                c = read();
            } while (c <= ' '); 
            if (c == '-') {
                sgn = -1;
                c = read();
            }
            while (c > ' ') {
                x = x * 10 + (c - '0');
                c = read();
            }
            return x * sgn;
        }
    }

    public static void main(String[] args) throws Exception {
        FastScanner fs = new FastScanner(System.in);
        StringBuilder out = new StringBuilder();

        int n = fs.nextInt();

        ArrayList<Integer> vals = new ArrayList<>();
        ArrayList<Integer> adds = new ArrayList<>();
        vals.add(0);
        adds.add(0);
        long total = 0;

   
        for (int i = 0; i < n; i++) {
            int t = fs.nextInt();
            if (t == 1) {
                int cnt = fs.nextInt();
                int val = fs.nextInt();

                total += (long) cnt * (long) val;
                adds.set(cnt - 1, adds.get(cnt - 1) + val);
            } else if (t == 2) {
                int val = fs.nextInt();

                total += val;
                vals.add(val);
                adds.add(0);
            } else { // t == 3
                int lastIndex = adds.size() - 1;
                adds.set(lastIndex - 1, adds.get(lastIndex - 1) + adds.get(lastIndex));
                total -= (long) adds.get(lastIndex) + (long) vals.get(vals.size() - 1);

                vals.remove(vals.size() - 1);
                adds.remove(adds.size() - 1);
            }

            double ans = (double) total / (double) vals.size();
            out.append(String.format("%.9f\n", ans));
        }

        System.out.print(out.toString());
    }
}
