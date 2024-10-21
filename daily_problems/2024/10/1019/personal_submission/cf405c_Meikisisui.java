import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] ji = new int[n + 1][n + 1];
        int res = 0;
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(f.readLine());
            for (int vn = 1; vn <= n; vn++)
                ji[ez][vn] = Integer.parseInt(st.nextToken());
        }
        for (int ez = 1; ez <= n; ez++) {
            for (int vn = 1; vn <= n; vn++)
                res += ji[ez][vn] * ji[vn][ez];
        }
        res %= 2;
        st = new StringTokenizer(f.readLine());
        int q = Integer.parseInt(st.nextToken());
        while (q-- > 0) {
            st = new StringTokenizer(f.readLine());
            int type = Integer.parseInt(st.nextToken());
            if (type != 3) {
                // 其实每次只需要对对角线变换，第二个参数没用……
                if (res == 0)
                    res = 1;
                else if (res == 1)
                    res = 0;
            } else
                pw.print(res);
        }
        pw.close();
        f.close();
    }

}
