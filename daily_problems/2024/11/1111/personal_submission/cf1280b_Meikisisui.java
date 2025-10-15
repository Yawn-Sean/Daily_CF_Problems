import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int t = Integer.parseInt(st.nextToken());
        for (int ez = 0; ez < t; ez++) {
            st = new StringTokenizer(f.readLine());
            int m = Integer.parseInt(st.nextToken());
            int n = Integer.parseInt(st.nextToken());
            char[][] grid = new char[m][n];
            for (int vn = 0; vn < m; vn++) {
                st = new StringTokenizer(f.readLine());
                grid[vn] = st.nextToken().toCharArray();
            }
            String res = getStep(grid);
            pw.println(res);
        }
        pw.close();
        f.close();
    }

    private static String getStep(char[][] grid) {
        // 存在大小写，分类讨论，需要若干变量
        // 都是a，返回0
        // 都是p，返回MORTAL
        // 四周一条边都是a，返回1
        // 一个角是a，返回2
        // 中间一行或一列都是a，返回2
        // 边上有个a，返回3
        // 否则返回4
        int m = grid.length, n = grid[0].length;
        int cntA = 0, cntP = 0, bianA1 = 0, bianA2 = 0, bianA3 = 0;
        for (int ez = 0; ez < m; ez++) {
            for (int vn = 0; vn < n; vn++) {
                char now = grid[ez][vn];
                if (now == 'a' || now == 'A')
                    cntA++;
                else
                    cntP++;
            }
        }

        if (cntA == m * n)
            return "0";
        if (cntP == m * n)
            return "MORTAL";

        for (int ez = 0; ez < m; ez++) {
            char now1 = grid[ez][0];
            char now2 = grid[ez][n - 1];
            if (now1 == 'a' || now1 == 'A') {
                bianA1++;
                bianA3++;
            }
            if (now2 == 'a' || now2 == 'A') {
                bianA2++;
                bianA3++;
            }
        }
        if (bianA1 == m || bianA2 == m)
            return "1";
        bianA1 = 0;
        bianA2 = 0;
        for (int vn = 0; vn < n; vn++) {
            char now1 = grid[0][vn];
            char now2 = grid[m - 1][vn];
            if (now1 == 'a' || now1 == 'A') {
                bianA1++;
                bianA3++;
            }
            if (now2 == 'a' || now2 == 'A') {
                bianA2++;
                bianA3++;
            }
        }
        if (bianA1 == n || bianA2 == n)
            return "1";

        if (grid[0][0] == 'a' || grid[0][n - 1] == 'a' || grid[0][0] == 'A' || grid[0][n - 1] == 'A'
                || grid[m - 1][0] == 'a' || grid[m - 1][n - 1] == 'a' || grid[m - 1][0] == 'A' || grid[m - 1][n - 1] == 'A')
            return "2";
        bianA1 = 0;
        bianA2 = 0;
        for (int ez = 1; ez < m - 1; ez++) {
            bianA1 = 0;
            for (int vn = 0; vn < n; vn++) {
                char now = grid[ez][vn];
                if (now == 'a' || now == 'A')
                    bianA1++;
            }
            if (bianA1 == n)
                return "2";
        }
        for (int vn = 1; vn < n - 1; vn++) {
            bianA2 = 0;
            for (int ez = 0; ez < m; ez++) {
                char now = grid[ez][vn];
                if (now == 'a' || now == 'A')
                    bianA2++;
            }
            if (bianA2 == m)
                return "2";
        }

        if (bianA3 > 0)
            return "3";
        return "4";
    }

}
