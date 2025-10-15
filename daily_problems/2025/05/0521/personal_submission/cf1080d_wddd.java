import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Math {

    void solve() {
        int t = is.ni();
        while (t > 0) {
            t--;

            long n = is.nl();
            long k = is.nl();

            split(n, k);
        }
    }

    private void split(long n, long k) {
        if (ceilLog2(3 * k + 1) > 2 * n) {
            out.println("NO");
            return;
        }
        if (n >= 32) {
            out.println("YES " + (n - 1));
            return;
        }

        int round = 1;
        long len = n;
        long min = 0;
        long max = 0;
        while (round <= n) {
            long normalCut = (1L << round) - 1;

            long newSquare = normalCut * 4;

            long greedySquare = newSquare / 2 - 1;

            long greedyLen = len - 1;

            long greedyCut = greedySquare * ((1L << (2 * greedyLen)) - 1) / 3;

            min += normalCut;
            max += normalCut + greedyCut;

            if (k >= min && k <= max) {
                out.println("YES " + greedyLen);
                return;
            }

            round++;
            len--;
        }

        out.println("NO");
    }

    public static int ceilLog2(long x) {
        int floor = 63 - Long.numberOfLeadingZeros(x);
        return (1L << floor) == x ? floor : floor + 1;
    }

}
