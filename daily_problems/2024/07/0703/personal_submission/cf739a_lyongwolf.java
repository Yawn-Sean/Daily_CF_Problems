import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), m = sc.nextInt();
        int[][] seg = new int[m][2];
        int mex = n;
        for (int i = 0; i < m; i++) {
            seg[i][0] = sc.nextInt() - 1;
            seg[i][1] = sc.nextInt() - 1;
            mex = Math.min(mex, seg[i][1] - seg[i][0] + 1);
        }
        Arrays.sort(seg, (i, j) -> i[0] == j[0] ? i[1] - j[1] : i[0] - j[0]);
        out.println(mex);
        int[] arr = new int[n];
        for (int i = 0, p = i, t = 0; i < m; i = p) {
            while (p < m && seg[i][0] == seg[p][0]) {
                p++;
            }
            int l = seg[i][0], r = seg[i][1];
            if (t <= l) {
                t = l;
                for (int j = 0; j < mex; j++) {
                    arr[t++] = j;
                }
            } else if (t <= r) {
                for (int j = t - mex; j < l; j++) {
                    arr[t++] = arr[j];
                }
            }
        }
        for (int v : arr) {
            out.print(v + " ");
        }
        out.println();
    }

}
