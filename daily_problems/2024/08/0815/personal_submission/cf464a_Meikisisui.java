import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    private static int[] nums = new int[1001];
    private static int n, p;

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        p = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String s = st.nextToken();
        for (int ez = 1; ez <= n; ez++)
            nums[ez] = s.charAt(ez - 1) - 'a' + 1;
        if (dfs(n)) {
            for (int ez = 1; ez <= n; ez++)
                pw.print((char) (nums[ez] + 'a' - 1));
        } else
            pw.println("NO");
        pw.close();
        f.close();
    }

    private static boolean dfs(int vn) {
        if (vn == 0)
            return false;
        // 从后向前尝试加1
        for (int ez = nums[vn] + 1; ez <= p; ez++) {
            if (vn - 1 >= 1 && nums[vn - 1] == ez)
                continue;
            if (vn - 2 >= 1 && nums[vn - 2] == ez)
                continue;
            nums[vn] = ez;
            return true;
        }
        if (!dfs(vn - 1))
            return false;
        // 从更改后下一位开始从a开始
        nums[vn] = 1;
        for (int ez = nums[vn]; ez <= p; ez++) {
            if (vn - 1 >= 1 && nums[vn - 1] == ez)
                continue;
            if (vn - 2 >= 1 && nums[vn - 2] == ez)
                continue;
            nums[vn] = ez;
            return true;
        }
        return false;
    }

}
