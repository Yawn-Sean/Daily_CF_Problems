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
        int x1 = Integer.parseInt(st.nextToken());
        int x2 = Integer.parseInt(st.nextToken());
        Long[][] nums = new Long[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            int k = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());
            nums[ez][0] = (long) k * x1 + b;
            nums[ez][1] = (long) k * x2 + b;
        }
        Arrays.sort(nums, (a, b) -> {
            if (0 == a[0].compareTo(b[0]))
                return a[1].compareTo(b[1]);
            return a[0].compareTo(b[0]);
        });
        boolean isX = false;
        for (int ez = 0; ez < n - 1; ez++) {
            if (nums[ez][0] <= nums[ez + 1][0] && nums[ez][1] <= nums[ez + 1][1])
                continue;
            else {
                isX = true;
                break;
            }
        }
        if (isX)
            pw.println("Yes");
        else
            pw.println("No");
        pw.close();
        f.close();
    }

}
