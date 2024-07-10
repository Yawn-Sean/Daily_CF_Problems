import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        int[] arr = new int[n];
        long[] sum = new long[n + 1];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        Arrays.sort(arr);
        for (int i = 0; i < n; i++) {
            sum[i + 1] = sum[i] + arr[i];
        }
        int len = 0;
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = 0, r = i, m;
            while (l <= r) {
                m = (l + r) >> 1;
                if ((long) arr[i] * (i - m + 1) - (sum[i + 1] - sum[m]) <= k) {
                    r = m - 1;
                } else {
                    l = m + 1;
                }
            }
            if (len < i - r) {
                len = i - r;
                ans = arr[i];
            }
        }
        out.println(len + " " + ans);
    }

}
