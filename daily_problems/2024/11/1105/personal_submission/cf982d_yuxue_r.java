import java.io.*;
import java.util.*;

public class cf982d {
    static class UnionFind {
        private int[] parent;
        private int[] size;

        public UnionFind(int n) {
            parent = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                parent[i] = i;
                size[i] = 1;
            }
        }

        public int find(int x) {
            while (x != parent[x]) {
                parent[x] = parent[parent[x]];
                x = parent[x];
            }
            return x;
        }

        public void merge(int x, int y) {
            int rootX = find(x);
            int rootY = find(y);
            if (rootX == rootY) return;
            if (size[rootX] < size[rootY]) {
                parent[rootX] = rootY;
                size[rootY] += size[rootX];
            } else {
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
            }
        }

        public int size(int x) {
            return size[find(x)];
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        int n = Integer.parseInt(br.readLine());
        int[] nums = new int[n];
        String[] input = br.readLine().split(" ");
        for (int i = 0; i < n; i++) {
            nums[i] = Integer.parseInt(input[i]);
        }

        Integer[] order = new Integer[n];
        for (int i = 0; i < n; i++) {
            order[i] = i;
        }
        Arrays.sort(order, (i, j) -> nums[i] - nums[j]);

        boolean[] vis = new boolean[n];
        int[] cnt = new int[n + 1];
        int total = 0, cur = -1, locations = 0;

        UnionFind dsu = new UnionFind(n);

        for (int p : order) {
            int sz;
            if (p > 0 && vis[p - 1]) {
                sz = dsu.size(p - 1);
                cnt[sz]--;
                dsu.merge(p, p - 1);
                total--;
            }

            if (p + 1 < n && vis[p + 1]) {
                sz = dsu.size(p + 1);
                cnt[sz]--;
                dsu.merge(p, p + 1);
                total--;
            }

            vis[p] = true;
            sz = dsu.size(p);
            cnt[sz]++;
            total++;
            if (cnt[sz] == total && total > locations) {
                cur = nums[p] + 1;
                locations = total;
            }
        }

        bw.write(cur + "\n");
        bw.flush();
        bw.close();
        br.close();
    }
}
