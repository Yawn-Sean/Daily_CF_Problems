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
        st = new StringTokenizer(f.readLine());
        int[] nums = new int[n];
        for (int ez = 0; ez < n; ez++)
            nums[ez] = Integer.parseInt(st.nextToken());
        int[] res = generatingSets(nums);
        for (int ez = 0; ez < n; ez++) {
            if (ez == n - 1)
                pw.print(res[ez]);
            else
                pw.print(res[ez] + " ");
        }
        pw.close();
        f.close();
    }

    private static int[] generatingSets(int[] nums) {
        int n = nums.length;
        Set<Integer> cntSet = new HashSet<>();
        PriorityQueue<Integer> pq = new PriorityQueue<>((x, y) -> {
            return y - x;
        });
        for (int ez : nums) {
            cntSet.add(ez);
            pq.offer(ez);
        }
        while (true) {
            int now = pq.poll();
            int temp = now;
            while (now > 0 && cntSet.contains(now))
                now /= 2;
            if (now > 0 && !cntSet.contains(now)) {
                pq.offer(now);
                cntSet.add(now);
                cntSet.remove(temp);
            } else {
                pq.offer(temp);
                break;
            }
        }
        int[] res = new int[n];
        for (int ez = 0; ez < n; ez++)
            res[ez] = pq.poll();
        return res;
    }

}
