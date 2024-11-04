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
        int m = Integer.parseInt(st.nextToken());
        int[][] nums = new int[m][n];
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(f.readLine());
            for (int vn = 0; vn < n; vn++)
                nums[ez][vn] = Integer.parseInt(st.nextToken());
        }
        PriorityQueue<int[]> resPq = new PriorityQueue<>((a, b) -> {
            return a[0] - b[0];
        });
        Map<Integer, List<Integer>> indexMap = new HashMap<>();
        for (int vn = 0; vn < n - 1; vn++) {
            PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> {
                return b[0] - a[0];
            });
            int sum = 0, cnt = 0;
            for (int ez = 0; ez < m; ez++) {
                int now = nums[ez][n - 1] - nums[ez][vn];
                sum += now;
                pq.offer(new int[]{now, ez});
            }
            List<Integer> removeList = new ArrayList<>();
            while (sum > 0) {
                int[] now = pq.poll();
                sum -= now[0];
                removeList.add(now[1] + 1);
            }
            cnt = pq.size();
            resPq.offer(new int[]{m - cnt, vn});
            indexMap.put(vn, removeList);
        }
        int[] fin = resPq.poll();
        pw.println(fin[0]);
        List<Integer> resList = indexMap.get(fin[1]);
        if (null != resList && resList.size() > 0) {
            for (int next : resList)
                pw.print(next + " ");
        }
        pw.close();
        f.close();
    }

}
