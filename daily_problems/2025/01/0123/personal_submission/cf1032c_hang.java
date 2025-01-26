import java.io.OutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.io.BufferedWriter;
import java.io.Writer;
import java.io.OutputStreamWriter;
import java.util.InputMismatchException;
import java.io.IOException;
import java.util.*;
import java.io.InputStream;
public class Main {

    public static void main(String[] args) {
       FastReader in = new FastReader(System.in);
       FastWriter out = new FastWriter(System.out);
       solve(in,out);
    }
    public static void solve(FastReader in, FastWriter out){
        int n = in.ni();
        int[] a = in.na(n);
        if(n == 1){
            out.println(1);
            out.flush();
            return;
        }
        int[] b = new int[n];
        if(a[0] < a[1]){
            b[0] = 1;
        }else {
            b[0] = 5;
        }
        for (int i = 1; i < n; i++) {
            if(a[i] > a[i-1]){
                if(i > 1 && a[i-1] <= a[i-2]){
                    b[i-1] = 1;
                    if(b[i-2] == 1){
                        b[i-1] = 2;
                    }
                }
                b[i] = b[i-1] + 1;
            }else if(a[i] < a[i-1]){
                if(i > 1 && a[i-1] >= a[i-2]){
                    b[i-1] = 5;
                    if(b[i-2] == 5){
                        b[i-1] = 4;
                    }
                }
                b[i] = b[i-1] - 1;
            }else {
                b[i] = (b[i-1] - 1) % 3 + 2;
            }
            if(b[i] < 1 || b[i] > 5){
                out.println(-1);
                out.flush();
                return;
            }
        }
        for (int i = 0; i < b.length; i++) {
            System.out.print(b[i] +" ");
        }
    }





}
class FastReader {
    InputStream is;

    public FastReader(final InputStream is) {
        this.is = is;
    }

    private byte[] inbuf = new byte[8192];
    public int lenbuf = 0, ptrbuf = 0;

    public int readByte() {
        if (lenbuf == -1) {
            throw new InputMismatchException();
        }
        if (ptrbuf >= lenbuf) {
            ptrbuf = 0;
            try {
                lenbuf = is.read(inbuf);
            } catch (IOException e) {
                throw new InputMismatchException();
            }
            if (lenbuf <= 0) {
                return -1;
            }
        }
        return inbuf[ptrbuf++];
    }

    private boolean isSpaceChar(int c) {
        return !(c >= 33 && c <= 126);
    }

    private int skip() {
        int b;
        while ((b = readByte()) != -1 && isSpaceChar(b))
            ;
        return b;
    }

    public double nd() {
        return Double.parseDouble(ns());
    }

    public char nc() {
        return (char) skip();
    }

    public String ns() {
        int b = skip();
        StringBuilder sb = new StringBuilder();
        while (!(isSpaceChar(b))) { // when nextLine, (isSpaceChar(b) && b != ' ')
            sb.appendCodePoint(b);
            b = readByte();
        }
        return sb.toString();
    }

    public char[] ns(int n) {
        char[] buf = new char[n];
        int b = skip(), p = 0;
        while (p < n && !(isSpaceChar(b))) {
            buf[p++] = (char) b;
            b = readByte();
        }
        return n == p ? buf : Arrays.copyOf(buf, p);
    }

    public int[] na(int n) {
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = ni();
        }
        return a;
    }

    public long[] nal(int n) {
        long[] a = new long[n];
        for (int i = 0; i < n; i++) {
            a[i] = nl();
        }
        return a;
    }

    public char[][] nm(int n, int m) {
        char[][] map = new char[n][];
        for (int i = 0; i < n; i++) {
            map[i] = ns(m);
        }
        return map;
    }

    public int[][] nmi(int n, int m) {
        int[][] map = new int[n][];
        for (int i = 0; i < n; i++) {
            map[i] = na(m);
        }
        return map;
    }

    public int ni() {
        int num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }

    public long nl() {
        long num = 0;
        int b;
        boolean minus = false;
        while ((b = readByte()) != -1 && !((b >= '0' && b <= '9') || b == '-'))
            ;
        if (b == '-') {
            minus = true;
            b = readByte();
        }

        while (true) {
            if (b >= '0' && b <= '9') {
                num = num * 10 + (b - '0');
            } else {
                return minus ? -num : num;
            }
            b = readByte();
        }
    }
}

class FastWriter {
    private final PrintWriter writer;

    public FastWriter(OutputStream outputStream) {
        writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
    }

    public FastWriter(Writer writer) {
        this.writer = new PrintWriter(writer);
    }

    public void println(long x) {
        writer.println(x);
    }

    public void flush() {
        writer.flush();
    }

    public void close() {
        writer.flush();
        try {
            writer.close();
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

}