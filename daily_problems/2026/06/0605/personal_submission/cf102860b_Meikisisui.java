import java.io.BufferedInputStream;
import java.io.BufferedOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;


@SuppressWarnings("DuplicatedCode")
public class Main {
    static int MAX_STRING_LENGTH = (int) 2e6; // 字符串最大长度
    static int MAX_DIGIT_LENGTH = (int) 1e6; // 数位最大长度
    static int MOD7 = (int) 1e9 + 7, MOD8 = 80112002, MOD9 = 998244353, inf = Integer.MAX_VALUE;

    public static void main(String[] args) {
        io = new IO();
        int T = 1;
//        int T = io.nextInt();
        while (T-- > 0)
            new Solution().solve();
        io.close();
    }

    static class Solution {

        void solve() {

            int n = io.nextInt();
            long L = io.nextLong();
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                a[i] = io.nextLong();
            }
            Arrays.sort(a);
            long[] b = new long[n * 2];
            for (int i = 0; i < n; i++) {
                b[i] = a[i];
                b[n + i] = a[i] + L;
            }
            long total = (long) n * (n - 1) * (n - 2) / 6;
            for (int i = 0, j = 0; i < n; i++) {
                while ((b[j] - b[i]) * 2 < L) {
                    j++;
                }
                long len = j - 1 - i;
                total -= len * (len - 1) / 2;
            }
            io.println(total);

        }

    }

    static IO io;

    static class IO {
        BufferedInputStream bis = new BufferedInputStream(System.in);
        PrintWriter pw = new PrintWriter(new BufferedOutputStream(System.out));

        int nextInt() {
            return (int) nextLong();
        }

        long nextLong() {
            try {
                long sign = 1, x = 0;
                int c = bis.read();
                while (c < '0' || c > '9') {
                    if (c == '-') sign = -1;
                    c = bis.read();
                }
                while (c >= '0' && c <= '9') {
                    x = x * 10 + (c - '0');
                    c = bis.read();
                }
                return sign * x;
            } catch (IOException e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        int[] nextIntArray(int n) {
            int[] a = new int[n];
            for (int i = 0; i < n; i++) {
                try {
                    int sign = 1, x = 0;
                    int c = bis.read();
                    while (c < '0' || c > '9') {
                        if (c == '-') sign = -1;
                        c = bis.read();
                    }
                    while (c >= '0' && c <= '9') {
                        x = x * 10 + (c - '0');
                        c = bis.read();
                    }
                    a[i] = sign * x;
                } catch (IOException e) {
                    throw new RuntimeException(e.getMessage());
                }
            }
            return a;
        }

        long[] nextLongArray(int n) {
            long[] a = new long[n];
            for (int i = 0; i < n; i++) {
                try {
                    long sign = 1, x = 0;
                    int c = bis.read();
                    while (c < '0' || c > '9') {
                        if (c == '-') sign = -1;
                        c = bis.read();
                    }
                    while (c >= '0' && c <= '9') {
                        x = x * 10 + (c - '0');
                        c = bis.read();
                    }
                    a[i] = sign * x;
                } catch (IOException e) {
                    throw new RuntimeException(e.getMessage());
                }
            }
            return a;
        }

        int[] nextDigitArray(int n) {
            try {
                int[] a = new int[n];
                int x = bis.read();
                while (ignore(x)) {
                    x = bis.read();
                }
                int i = 0;
                while (!ignore(x)) {
                    a[i++] = x - '0';
                    x = bis.read();
                }
                return a;
            } catch (Exception e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        private int[] DIGIT_ARRAY;

        int[] nextDigitArray() {
            try {
                if (DIGIT_ARRAY == null) {
                    DIGIT_ARRAY = new int[MAX_DIGIT_LENGTH];
                }
                int x = bis.read();
                while (ignore(x)) {
                    x = bis.read();
                }
                int m = 0;
                while (!ignore(x)) {
                    DIGIT_ARRAY[m++] = x - '0';
                    x = bis.read();
                }
                int[] a = new int[m];
                System.arraycopy(DIGIT_ARRAY, 0, a, 0, m);
                return a;
            } catch (Exception e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        char nextChar() {
            try {
                int x = bis.read();
                while (ignore(x)) {
                    x = bis.read();
                }
                return (char) x;
            } catch (Exception e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        String[] nextStringArray(int n) {
            String[] a = new String[n];
            for (int i = 0; i < n; i++) {
                try {
                    if (CHAR_ARRAY == null) {
                        CHAR_ARRAY = new char[MAX_STRING_LENGTH];
                    }
                    int x = bis.read();
                    while (ignore(x)) {
                        x = bis.read();
                    }
                    int m = 0;
                    while (x != ' ' && x != ',' && !ignore(x)) {
                        CHAR_ARRAY[m++] = (char) x;
                        x = bis.read();
                    }
                    a[i] = new String(CHAR_ARRAY, 0, m);
                } catch (IOException e) {
                    throw new RuntimeException(e.getMessage());
                }
            }
            return a;
        }

        private char[] CHAR_ARRAY;

        char[] nextCharArray(boolean line) {
            try {
                if (CHAR_ARRAY == null) {
                    CHAR_ARRAY = new char[MAX_STRING_LENGTH];
                }
                int x = bis.read();
                while (ignore(x)) {
                    x = bis.read();
                }
                int m = 0;
                while (line ? (x == ' ' || x == ',' || !ignore(x)) : !ignore(x)) {
                    CHAR_ARRAY[m++] = (char) x;
                    x = bis.read();
                }
                char[] a = new char[m];
                System.arraycopy(CHAR_ARRAY, 0, a, 0, m);
                return a;
            } catch (Exception e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        char[] nextCharArray(int n) {
            try {
                char[] a = new char[n];
                int x = bis.read();
                while (ignore(x)) {
                    x = bis.read();
                }
                int i = 0;
                while (!ignore(x)) {
                    a[i++] = (char) x;
                    x = bis.read();
                }
                return a;
            } catch (Exception e) {
                throw new RuntimeException(e.getMessage());
            }
        }

        private boolean ignore(int c) {
            return c == ' ' || c == '\n' || c == '\r' || c == '\t' || c == -1;
        }

        String nextString(boolean line) {
            return new String(nextCharArray(line));
        }

        String nextString() {
            return nextString(false);
        }

        boolean nextBoolean() {
            return "true".equalsIgnoreCase(nextString());
        }

        double nextDouble() {
            return Double.parseDouble(nextString());
        }

        void println(Object obj) {
            print(obj);
            print("\n");
        }

        void println() {
            print('\n');
        }

        void print(Object obj) {
            pw.print(obj);
        }

        void printf(String format, Object... obj) {
            pw.printf(format, obj);
        }

        void close() {
            try {
                if (bis != null) bis.close();
                if (pw != null) {
                    pw.flush();
                    pw.close();
                }
                bis = null;
                pw = null;
            } catch (Exception ignore) {
            }
        }
    }
}
