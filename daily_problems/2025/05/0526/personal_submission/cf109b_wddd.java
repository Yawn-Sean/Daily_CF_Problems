import java.io.*;
import java.util.*;

public class BruteForce {

    void solve() {
        long pl = is.nl();
        long pr = is.nl();
        long vl = is.nl();
        long vr = is.nl();
        int k = is.ni();

        List<Long> lucky = new ArrayList<>();
        lucky.add(4L);
        lucky.add(7L);
        int p = 0;
        while (p < lucky.size()) {
            long curr = lucky.get(p);
            if (curr * 10 + 4 <= 1e9) {
                lucky.add(curr * 10 + 4);
            }
            if (curr * 10 + 7 <= 1e9) {
                lucky.add(curr * 10 + 7);
            }
            p++;
        }

        Collections.sort(lucky);

        long valid = 0;
        for (int i = 0; i + k - 1 < lucky.size(); i++) {
            long lr = lucky.get(i);
            long rl = lucky.get(i + k - 1);
            long ll = i > 0 ? lucky.get(i - 1) + 1 : 1;
            long rr = i + k < lucky.size() ? lucky.get(i + k) - 1 : (long) 1e9;

            long valid1 = pairs(pl, pr, ll, lr) * pairs(vl, vr, rl, rr);
            long valid2 = pairs(pl, pr, rl, rr) * pairs(vl, vr, ll, lr);
            valid += valid1 + valid2;
            if (k == 1 && valid1 > 0 && valid2 > 0) {
                valid--;
            }
        }

        double result = (double) valid / (pr - pl + 1) / (vr - vl + 1);
        out.printf("%.12f\n", result);
    }

    private long pairs(long pl, long pr, long ll, long lr) {
        long[] in = intersect(pl, pr, ll, lr);
        if (in == null) {
            return 0;
        } else {
            return in[1] - in[0] + 1;
        }
    }

    private long[] intersect(long a, long b, long c, long d) {
        if (b < c || a > d) {
            return null;
        }

        return new long[] {Math.max(a, c), Math.min(b, d)};
    }

}
