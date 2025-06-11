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
        int T = Integer.parseInt(st.nextToken());
        while (T-- > 0) {
            st = new StringTokenizer(f.readLine());
            int r = Integer.parseInt(st.nextToken());
            int c = Integer.parseInt(st.nextToken());
            int k = Integer.parseInt(st.nextToken());
            char[][] grid = new char[r][c];
            for (int ez = 0; ez < r; ez++) {
                st = new StringTokenizer(f.readLine());
                grid[ez] = st.nextToken().toCharArray();
            }
            int rice = 0;
            for (int ez = 0; ez < r; ez++) {
                for (int vn = 0; vn < c; vn++) {
                    if (grid[ez][vn] == 'R')
                        rice++;
                }
            }
            int cur = 0, index = 0;
            char[] s = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz1234567890".toCharArray();
            char[][] res = new char[r][c];
            for (int ez = 0; ez < r; ez++)
                for (int vn = ez % 2 == 0 ? 0 : c - 1;
                     vn >= 0 && vn < c;
                     vn += (ez % 2 == 0 ? 1 : -1)) {
                    res[ez][vn] = s[index];
                    if (grid[ez][vn] == 'R')
                        cur++;
                    if (cur >= (rice + k - 1) / k && k > 1) {
                        rice -= cur;
                        k--;
                        index++;
                        cur = 0;
                    }
                }
            for (int ez = 0; ez < r; ez++) {
                for (int vn = 0; vn < c; vn++)
                    pw.print(res[ez][vn]);
                pw.println();
            }
        }
        pw.close();
        f.close();
    }

}
