import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        long[][] lands = new long[n][2];
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(f.readLine());
            long nowX = Long.parseLong(st.nextToken());
            long nowY = Long.parseLong(st.nextToken());
            if (nowX > nowY) {
                lands[ez][0] = nowY;
                lands[ez][1] = nowX;
            } else {
                lands[ez][1] = nowY;
                lands[ez][0] = nowX;
            }
        }
        // 长边大到小排序
        Arrays.sort(lands, (a, b) -> Long.compare(b[1], a[1]));
        long res = lands[0][0] * lands[0][1], maxX = lands[0][0];
        for (int ez = 1; ez < n; ez++) {
            res = Math.max(res, lands[ez][0] * lands[ez][1]);
            // 当前的长边当作建筑的一边，之前的最长的短边与现在的短边取最小值
            res = Math.max(res, Math.min(maxX, lands[ez][0]) * lands[ez][1] * 2);
            maxX = Math.max(maxX, lands[ez][0]);
        }
        if (res % 2 == 1)
            pw.println(res / 2 + ".5");
        else
            pw.println(res / 2 + ".0");
        pw.close();
        f.close();
    }

}
