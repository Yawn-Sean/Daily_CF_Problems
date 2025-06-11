import java.util.*;
import java.io.*;

public class Main {

    static void solve() {
        int n = sc.nextInt();
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }
        TreeSet<Integer> set = new TreeSet<>();
        for (int v : arr) {
            set.add(v);
        }
        int j = 0;
        HashMap<Integer, Integer> map = new HashMap<>();
        for (int v : set) {
            map.put(v, ++j);
        }
        if (j < n) {
            out.println("YES");
            return;
        }
        IndexTree tree = new IndexTree(j + 1);
        for (int i = 0; i < n; i++) {
            arr[i] = map.get(arr[i]);
        }
        long cnt = 0;
        for (int i = 0; i < n; i++) {
            cnt += tree.query(j + 1) - tree.query(arr[i]);
            tree.add(arr[i], 1);
        }
        out.println(cnt % 2 != 0 ? "NO" : "YES");
    }

    static class IndexTree {
        private int[] sum;
        private int N;

        public IndexTree(int len) {
            N = len + 1;
            sum = new int[N];
        }

        public void add(int i, int v) {
            while (i < N) {
                sum[i] += v;
                i += i & -i;
            }
        }

        public int query(int i) {
            int ans = 0;
            while (i > 0) {
                ans += sum[i];
                i -= i & -i;
            }
            return ans;
        }
    }

}
