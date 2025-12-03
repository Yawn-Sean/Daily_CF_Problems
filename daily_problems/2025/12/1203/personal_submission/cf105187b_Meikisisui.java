import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    private static int MOD = 1000000007;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] scores = new int[2 * n];
        for (int ez = 0; ez < 2 * n; ez++)
            scores[ez] = Integer.parseInt(st.nextToken());
        int[][] competitions = new int[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            competitions[ez][0] = Integer.parseInt(st.nextToken());
            competitions[ez][1] = Integer.parseInt(st.nextToken());
        }
        Fenwick tree1 = new Fenwick(500005);
        for (int[] comp : competitions) {
            int left = comp[0];
            int right = comp[1];
            int x = scores[left];
            int y = scores[right];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            tree1.add(x, 1);
            tree1.add(Math.min(Math.max(x + 1, y + 1), Math.max(x + 3, y)), 1);
        }
        int[] res = new int[2 * n];
        for (int[] comp : competitions) {
            int left = comp[0];
            int right = comp[1];
            int x = scores[left];
            int y = scores[right];
            if (x > y) {
                int temp = x;
                x = y;
                y = temp;
            }
            tree1.add(x, -1);
            tree1.add(Math.min(Math.max(x + 1, y + 1), Math.max(x + 3, y)), -1);
            res[left] = 2 * n - tree1.sum(scores[left] + 3);
            res[right] = 2 * n - tree1.sum(scores[right] + 3);
            if (scores[left] + 3 >= scores[right])
                res[left]--;
            if (scores[right] + 3 >= scores[left])
                res[right]--;
            tree1.add(x, 1);
            tree1.add(Math.min(Math.max(x + 1, y + 1), Math.max(x + 3, y)), 1);
        }
        for (int x : res)
            pw.print(x + " ");
        pw.close();
    }

    private static class Fenwick {
        private final int[] tree;
        private final int size;

        public Fenwick(int size) {
            this.size = size;
            tree = new int[size + 1];
        }

        public void add(int index, int value) {
            for (int i = index + 1; i <= size; i += i & -i) {
                tree[i] += value;
            }
        }

        // 返回下标在 [1,i] 的元素之和
        public int sum(int index) {
            int res = 0;
            for (int i = index + 1; i > 0; i -= i & -i)
                res += tree[i];
            return res;
        }

        public int sum(int left, int right) {
            return sum(right) - sum(left - 1);
        }
    }

}
