import java.io.*;
import java.util.*;

public class cf1085d_lyongwolf {
    static void solve() {
        int n = sc.nextInt(), s = sc.nextInt();
        int[] d = new int[n + 1];
        for (int i = 1; i < n; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            d[u]++;
            d[v]++;
        }
        int cnt = 0;
        for (int v : d) {
            if (v == 1) {
                cnt++;
            }
        }
        out.println((double) s * 2 / cnt);
    }
}
