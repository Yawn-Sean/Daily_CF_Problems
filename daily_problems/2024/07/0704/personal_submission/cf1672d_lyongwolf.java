import java.util.*;
import java.io.*;

public class Main {
    
    static void solve() {
        int n = sc.nextInt();
        int[] a = new int[n], b = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < n; i++) {
            b[i] = sc.nextInt();
        }
        int[] cnt = new int[n + 1];
        int i = 0;
        for (int v : a) {
            if (v == b[i]) {
                i++;
            } else {
                cnt[v]++;
            }
            while (i < n && i > 0 && b[i] == b[i - 1] && cnt[b[i]] > 0) {
                cnt[b[i++]]--;
            }
        }
        out.println(i == n ? "Yes" : "No");
    }

}
