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
        int nums[][] = new int[n][3];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            nums[ez][0] = Integer.parseInt(st.nextToken());
            nums[ez][1] = Integer.parseInt(st.nextToken());
            nums[ez][2] = ez + 1;
        }
        st = new StringTokenizer(f.readLine());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        int tables[][] = new int[k][2];
        for (int ez = 0; ez < k; ez++) {
            tables[ez][0] = Integer.parseInt(st.nextToken());
            tables[ez][1] = ez + 1;
        }
        Arrays.sort(tables, (a, b) -> a[0] - b[0]);
        Arrays.sort(nums, (a, b) -> b[1] - a[1]);
        int money = 0;
        ArrayList<int[]> res = new ArrayList<>();
        for (int ez = 0; ez < n; ez++) {
            int p = nums[ez][0];
            for (int vn = 0; vn < k; vn++) {
                if (tables[vn][0] >= p) {
                    tables[vn][0] = -1;
                    money += nums[ez][1];
                    res.add(new int[]{nums[ez][2], tables[vn][1]});
                    break;
                }
            }
        }
        pw.println(res.size() + " " + money);
        for (int[] ez : res)
            pw.println(ez[0] + " " + ez[1]);
        pw.close();
        f.close();
    }

}
