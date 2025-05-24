import java.io.*;
import java.util.*;

public class Simulation1 {

    void solve() {
        long w = is.nl();
        long m = is.nl();
        long k = is.nl();

        w /= k;
        long max = maxSeq(w, m);
        out.println(max);
    }

    private long maxSeq(long w, long m) {
        int s = String.valueOf(m).length();
        long next = (long) Math.pow(10L, s);

        long total = (next - m) * s;
        if (total >= w) {
            return w / s;
        } else {
            return next - m + maxSeq(w - total, next);
        }
    }

}
