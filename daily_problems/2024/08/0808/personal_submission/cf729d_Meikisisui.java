import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.*;

public class Test2 {

    public static void main(String[] args) throws Exception {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int k = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(f.readLine());
        String str = st.nextToken();
        int vn = 0, cnt = 0;
        int[] point = new int[n];
        for (int ez = 0; ez < n; ez++) {
            char now = str.charAt(ez);
            if ('0' == now) {
                vn++;
                if (vn == b) {
                    point[cnt++] = ez + 1;
                    vn = 0;
                }
            } else
                vn = 0;
        }
        cnt -= a - 1;
        pw.println(cnt);
        for (int ez = 0; ez < n; ez++) {
            if (cnt > 0) {
                if (point[ez] > 0 && cnt-- > 1)
                    pw.print(point[ez] + " ");
                else if (point[ez] > 0)
                    pw.print(point[ez]);
            }
        }
        pw.close();
        f.close();
    }

}
