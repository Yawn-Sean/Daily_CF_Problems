import java.util.*;
import java.io.*;

public class Main {
    
    static void solve() {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        int[][] val = new int[n + 1][];
        TreeSet<Integer> set = new TreeSet<>();
        TreeSet<int[]> seg = new TreeSet<>((i, j) -> i[0] == j[0] ? i[1] - j[1] : j[0] - i[0]);
        for (int i = 0, j = i, k = 0; i < n; i = j) {
            while (j < n && arr[j] == arr[i]) {
                j++;
            }
            k++;
            int[] tup = new int[]{j - i, k, arr[i]};
            val[k] = tup;
            set.add(k);
            seg.add(tup);
        }
        int ans = 0;
        while (!seg.isEmpty()) {
            ans++;
            int[] s = seg.pollFirst();
            int k = s[1];
            set.remove(k);
            Integer floor = set.floor(k), ceiling = set.ceiling(k);
            if (floor == null || ceiling == null) {
                continue;
            }
            int[] left = val[floor], right = val[ceiling];
            if (left[2] == right[2]) {
                seg.remove(left);
                seg.remove(right);
                set.remove(ceiling);
                int[] tup = {left[0] + right[0], left[1], left[2]};
                val[floor] = tup;
                seg.add(tup);
            }
        }
        out.println(ans);
    }

}
