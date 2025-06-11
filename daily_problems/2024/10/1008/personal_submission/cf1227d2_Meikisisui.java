import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int arr[][] = new int[n][2];
        int value[] = new int[n];
        st = new StringTokenizer(f.readLine());
        for (int ez = 0; ez < n; ez++) {
            arr[ez][0] = Integer.parseInt(st.nextToken());
            arr[ez][1] = ez;
            value[ez] = arr[ez][0];
        }
        st = new StringTokenizer(f.readLine());
        int m = Integer.parseInt(st.nextToken());
        int q[][] = new int[m][3];
        int res[] = new int[m];
        int nums[] = new int[n];
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            q[ez][0] = Integer.parseInt(st.nextToken());
            q[ez][1] = Integer.parseInt(st.nextToken()) - 1;
            q[ez][2] = ez;
        }
        Arrays.sort(arr, (a, b) -> {
            if (a[0] == b[0])
                return a[1] - b[1];
            return b[0] - a[0];
        });
        Arrays.sort(q, (a, b) -> {
            return a[0] - b[0];
        });
        Fenwick fen = new Fenwick(nums);
        int vn = 0;
        for (int ez = 0; ez < m; ez++) {
            int ks = q[ez][0], ith = q[ez][1], index = q[ez][2];
            while (vn <= ks - 1) {
                fen.update(arr[vn][1], 1);
                vn++;
            }
            int left = 0, right = n - 1;
            int pos = -1;
            while (left <= right) {
                int mid = left + (right - left) / 2;
                int sum = fen.sumRange(0, mid);
                if (sum >= ith + 1) {
                    pos = mid;
                    right = mid - 1;
                } else
                    left = mid + 1;
            }
            res[index] = value[pos];
        }
        for (int right : res)
            pw.println(right);
        pw.close();
        f.close();
    }

    private static class Fenwick {

        int tree[];
        int nums[];
        int arr[];

        public Fenwick(int[] nums) {
            this.nums = nums;
            int n = nums.length;
            arr = new int[n];
            tree = new int[n + 1];
            int sum = 0;
            for (int ez = 0; ez < n; ez++)
                update(ez, nums[ez]);
        }

        public void update(int ez, int val) {
            arr[ez] += val;
            ez++;
            while (ez < tree.length) {
                tree[ez] += val;
                ez += (ez & -ez);
            }
        }

        public int sumRange(int ez, int vn) {
            return pre(vn + 1) - pre(ez);
        }

        public int pre(int ez) {
            int sum = 0;
            while (ez > 0) {
                sum += tree[ez];
                ez -= (ez & -ez);
            }
            return sum;
        }
    }

}
