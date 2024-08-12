import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt();
        int[] x = new int[n + 1], y = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            x[i] = sc.nextInt();
            y[i] = sc.nextInt();
        }
        int[] map = new int[100001];
        for (int i = 1; i <= n; i++) {
            int v = x[i], l = i - y[i], cnt = 0;
            for (int j = 1; (long) j * j <= v; j++) {
                if (v % j == 0) {
                    if (map[j] < l) {
                        cnt++;
                    }
                    map[j] = i;
                    if (j * j != v) {
                        if (map[v / j] < l) {
                            cnt++;
                        }
                        map[v / j] = i;
                    }
                }
            }
            out.println(cnt);
        }
    }

}
