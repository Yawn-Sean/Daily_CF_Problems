import java.io.*;
import java.util.StringTokenizer;


private static void solve() {
    int n = sc.nextInt(), m = sc.nextInt();
    int[] rows = new int[n], cols = new int[m];
    for (int i = 0; i < n; i++) rows[i] = sc.nextInt();
    for (int i = 0; i < m; i++) cols[i] = sc.nextInt();
    // verify
    int row = rows[0], col = cols[0];
    for (int i = 1; i < n; i++) row ^= rows[i];
    for (int i = 1; i < m; i++) col ^= cols[i];
    if (row != col) {
        out.println("NO");
        return;
    }out.println("YES");
    int cur = rows[0];
    for (int i = 1; i < m; i++) {
        cur ^= cols[i];
    }
    out.print(cur + " ");
    for (int i = 1; i < m; i++) {
        out.print(cols[i] + " ");
    }
    out.println();
    for (int i = 1; i < n; i++) {
        out.print(rows[i] + " ");
        for (int j = 1; j < m; j++) out.print(0 + " ");
        out.println();
    }


}
