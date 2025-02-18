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
        int[] a = new int[n + 1];
        List<Integer>[] res = new List[n + 1];
        Arrays.setAll(res, e -> new ArrayList<>());
        st = new StringTokenizer(f.readLine());
        for (int ez = 1; ez <= n; ez++) {
            int temp = Integer.parseInt(st.nextToken());
            int pos = lowerBound(a, 1, n, temp) - 1;
            a[pos] = temp;
            res[pos].add(temp);
        }
        for (int ez = n; ez >= 0; ez--) {
            for (int vn = 0; vn < res[ez].size(); vn++) {
                if (vn == res[ez].size() - 1)
                    pw.println(res[ez].get(vn));
                else
                    pw.print(res[ez].get(vn) + " ");
            }
        }
        pw.close();
        f.close();
    }

    private static int lowerBound(int[] nums, int left, int right, int tagret) {
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < tagret)
                left = mid + 1;
            else
                right = mid;
        }
        return left;
    }

}
