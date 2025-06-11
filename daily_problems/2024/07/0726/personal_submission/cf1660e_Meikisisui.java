import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int m = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < m; ez++) {
            f.readLine();
            st = new StringTokenizer(f.readLine());
            int n = Integer.parseInt(st.nextToken());
            // n*n矩形
            int[][] nums = new int[n][n];
            for (int vn = 0; vn < n; vn++) {
                String str = f.readLine();
                for (int jx = 0; jx < n; jx++)
                    nums[vn][jx] = Integer.parseInt(String.valueOf(str.charAt(jx)));
            }
            int res = getLineNum(n, nums);
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static int getLineNum(int n, int[][] nums) {
        // 1个数,对角线1个数
        int oneNum = 0, lineOneNum = 0;
        for (int ez = 0; ez < n; ez++) {
            for (int vn = 0; vn < n; vn++) {
                if (nums[ez][vn] == 1)
                    oneNum++;
            }
        }
        for (int ez = 0; ez < n; ez++) {
            int offset = 0, temp = 0;
            for (int vn = 0; vn < n; vn++) {
                if (nums[(ez + offset) % n][vn] == 1) {
                    temp++;
                    lineOneNum = Math.max(lineOneNum, temp);
                }
                offset++;
            }
        }
        return n - lineOneNum * 2 + oneNum;
    }

}
