import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), k = sc.nextInt();
        int[][] seg = new int[n][3];
        HashSet<Integer> set = new HashSet<>();
        for (int i = 0; i < n; i++) {
            seg[i][0] = sc.nextInt();
            seg[i][1] = sc.nextInt();
            set.add(seg[i][0]);
            set.add(seg[i][1]);
            seg[i][2] = i + 1;
        }
        int t = 0;
        int[] arr = new int[set.size()];
        for (int v : set) {
            arr[t++] = v;
        }
        Arrays.sort(arr);
        Arrays.sort(seg, (i, j) -> Integer.compare(i[0], j[0]));
        PriorityQueue<int[]> heap = new PriorityQueue<>((i, j) -> Integer.compare(i[0], j[0]));
        int r = 0;
        long ans = 0;
        for (int[] s : seg) {
            while (arr[r] < s[0]) {
                r++;
            }
            while (!heap.isEmpty() && heap.peek()[0] < arr[r]) {
                heap.poll();
            }
            if (heap.size() == k && heap.peek()[0] < s[1]) {
                heap.poll();
            }
            if (heap.size() < k) {
                heap.add(new int[]{s[1], s[2]});
            }
            if (heap.size() == k) {
                ans = Math.max(ans, (long) heap.peek()[0] - arr[r] + 1);
            }
        }
        out.println(ans);
        if (ans == 0) {
            for (int i = 1; i <= k; i++) {
                out.print(i + " ");
            }
            out.println();
            return;
        }
        heap.clear();
        r = 0;
        long cur = 0;
        for (int[] s : seg) {
            while (arr[r] < s[0]) {
                r++;
            }
            while (!heap.isEmpty() && heap.peek()[0] < arr[r]) {
                heap.poll();
            }
            if (heap.size() == k && heap.peek()[0] < s[1]) {
                heap.poll();
            }
            if (heap.size() < k) {
                heap.add(new int[]{s[1], s[2]});
            }
            if (heap.size() == k) {
                cur = Math.max(cur, (long) heap.peek()[0] - arr[r] + 1);
                if (cur == ans) {
                    for (int[] tup : heap) {
                        out.print(tup[1] + " ");
                    }
                    out.println();
                    return;
                }
            }
        }
    }

}
