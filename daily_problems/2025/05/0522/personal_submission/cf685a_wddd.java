import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

public class BruteForce1 {

    void solve() {
        long n = is.nl();
        long m = is.nl();

        String num1 = Long.toString(n - 1, 7);
        String num2 = Long.toString(m - 1, 7);

        if (num1.length() > 7 || num2.length() > 7) {
            out.println(0);
            return;
        }

        long result = search1(num1, num2, 0, false, new boolean[7]);
        out.println(result);
    }

    private long search1(String num1, String num2, int ind, boolean smaller, boolean[] picked) {
        if (ind >= num1.length()) {
            return search2(num2, 0, false, picked);
        }

        long result = 0;
        int start = smaller ? 6 : (num1.charAt(ind) - '0');
        for (int i = start; i >= 0; i--) {
            if (picked[i]) {
                continue;
            }
            picked[i] = true;
            result += search1(num1, num2, ind + 1, smaller || i < num1.charAt(ind) - '0', picked);
            picked[i] = false;
        }

        return result;
    }

    private long search2(String num, int ind, boolean smaller, boolean[] picked) {
        if (ind >= num.length()) {
            return 1;
        }
        if (smaller) {
            int remaining = 0;
            for (int i = 0; i < picked.length; i++) {
                if (!picked[i]) {
                    remaining++;
                }
            }
            return arrangement(remaining, num.length() - ind);
        }

        long result = 0;
        int start = num.charAt(ind) - '0';
        for (int i = start; i >= 0; i--) {
            if (picked[i]) {
                continue;
            }
            picked[i] = true;
            result += search2(num, ind + 1, i < num.charAt(ind) - '0', picked);
            picked[i] = false;
        }

        return result;
    }

    private long arrangement(int a, int b) {
        if (b > a) {
            return 0;
        }

        long result = 1;
        for (int i = a - b + 1; i <= a; i++) {
            result *= i;
        }
        return result;
    }

}
