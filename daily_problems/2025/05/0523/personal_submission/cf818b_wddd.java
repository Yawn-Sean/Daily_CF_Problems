import java.io.*;
import java.util.*;

public class BruteForce1 {

    void solve() {
        int n = is.ni();
        int m = is.ni();
        int[] l = is.na(m);

        int[] a = new int[n + 1];
        Arrays.fill(a, -1);
        boolean[] used = new boolean[n + 1];

        for (int i = 0; i < l.length - 1; i++) {
            int val = l[i + 1] - l[i];
            if (val <= 0) {
                val += n;
            }
            if (a[l[i]] == val) {
                continue;
            } else if (a[l[i]] > 0) {
                out.println(-1);
                return;
            }
            a[l[i]] = val;
            if (used[a[l[i]]]) {
                out.println(-1);
                return;
            } else {
                used[a[l[i]]] = true;
            }
        }

        int p = 1;
        for (int i = 1; i <= n; i++) {
            if (a[i] == -1) {
                while (used[p]) {
                    p++;
                }
                a[i] = p;
                used[p] = true;
            }
        }

        for (int i = 1; i <= n; i++) {
            out.print(a[i] + " ");
        }
        out.println();
    }

}
