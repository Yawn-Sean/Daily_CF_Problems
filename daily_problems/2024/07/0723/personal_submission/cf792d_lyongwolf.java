import java.io.*;
import java.util.*;

public class Main {

    static void solve() {
        long n = sc.nextLong(), q = sc.nextInt();
        long root = (n + 1) / 2;
        while (q-- > 0) {
            long u = sc.nextLong();
            for (char c : sc.next().toCharArray()) {
                if (c == 'L') {
                    if ((u & 1) != 0) {
                        continue;
                    }
                    u -= (u & -u) / 2;
                } else if (c == 'R') {
                    if ((u & 1) != 0) {
                        continue;
                    }
                    u += (u & -u) / 2;
                } else {
                    if (u == root) {
                        continue;
                    }
                    if ((u & 1) != 0) {
                        if (u % 4 == 1) {
                            u++;
                        } else {
                            u--;
                        }
                    } else {
                        long s = (u & -u);
                        long t = u + s;
                        if (t - (t & -t) / 2 == u) {
                            u = t;
                        } else {
                            u -= s;
                        }
                    }
                }
            }
            out.println(u);
        }
    }

}
