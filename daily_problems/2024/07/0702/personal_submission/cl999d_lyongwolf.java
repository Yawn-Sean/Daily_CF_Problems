import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt(), m = sc.nextInt(), k = n / m;
        int[] arr = new int[n];
        int[] cnt = new int[m];
        Deque<Integer>[] op = new Deque[m];
        Arrays.setAll(op, v -> new ArrayDeque<>());
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
            op[arr[i] % m].addLast(i);
            cnt[arr[i] % m]++;
        }
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int i = 0; i < m; i++) {
            if (cnt[i] > k) {
                map.put(i, cnt[i] - k);
            }
        }
        long ans = 0;
        for (int i = 0; i < m; i++) {
            if (cnt[i] < k) {
                int c = k - cnt[i];
                Integer floor = map.floorKey(i - 1);
                while (floor != null && c > 0) {
                    int v = map.get(floor);
                    int t = Math.min(c, v);
                    for (int s = 0; s < t; s++) {
                        arr[op[floor].removeFirst()] += i - floor;
                    }
                    ans += (long) t * (i - floor);
                    c -= t;
                    v -= t;
                    if (v == 0) {
                        map.remove(floor);
                        floor = map.floorKey(i - 1);
                    } else {
                        map.put(floor, v);
                    }
                }
                while (c > 0) {
                    Integer last = map.lastKey();
                    int v = map.get(last);
                    int t = Math.min(c, v);
                    for (int s = 0; s < t; s++) {
                        arr[op[last].removeFirst()] += i + m - last;
                    }
                    ans += (long) t * (i + m - last);
                    c -= t;
                    v -= t;
                    if (v == 0) {
                        map.remove(last);
                        if (!map.isEmpty()) {
                            last = map.lastKey();
                        }
                    } else {
                        map.put(last, v);
                    }
                }
            }
        }
        out.println(ans);
        for (int v : arr) {
            out.print(v + " ");
        }
        out.println();
    }

}
