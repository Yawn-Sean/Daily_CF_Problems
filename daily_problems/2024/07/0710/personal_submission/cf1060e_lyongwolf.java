import java.util.*;
import java.io.*;

public class Main {

    static int n;
    static int[] head, nxt, to, siz, odd, even;
    static long ans;

    static void solve() {
        n = sc.nextInt();
        head = new int[n + 1];
        nxt = new int[n << 1];
        to = new int[n << 1];
        siz = new int[n + 1];
        odd  = new int[n + 1];
        even  = new int[n + 1];
        for (int i = 1, j = 2; i < n; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            nxt[j] = head[u]; head[u] = j; to[j++] = v;
            nxt[j] = head[v]; head[v] = j; to[j++] = u;
        }
        dfs(0, 1);
        ans = 0;
        dfs2(0, 1, 0, 0);
        out.println(ans / 4);
    }

    static void dfs2(int f, int u, int preEven, int preOdd) {
        ans += preOdd + odd[u];
        for (int e = head[u], v = to[e]; e != 0; e = nxt[e], v = to[e]) {
            if (f != v) {
                ans += (long) siz[v] * (n - siz[v]) * 2;
                int curEven = preOdd + odd[u] - even[v] - 1;
                int curOdd= preEven + even[u] - odd[v] + 1;
                dfs2(u, v, curEven, curOdd);
            }
        }
    }

    static void dfs(int f, int u) {
        siz[u] = 1;
        for (int e = head[u], v = to[e]; e != 0; e = nxt[e], v = to[e]) {
            if (f != v) {
                dfs(u, v);
                siz[u] += siz[v];
                odd[u] += even[v] + 1;
                even[u] += odd[v];
            }
        }
    }

}
