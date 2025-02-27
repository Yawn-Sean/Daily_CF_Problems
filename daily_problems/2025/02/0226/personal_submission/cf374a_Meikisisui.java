import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int i = Integer.parseInt(st.nextToken());
        int j = Integer.parseInt(st.nextToken());
        int a = Integer.parseInt(st.nextToken());
        int b = Integer.parseInt(st.nextToken());
        int res = Integer.MAX_VALUE;
        int[] sx = {1, n};
        int[] sy = {1, m};
        // 起点在角上
        if ((i == 1 || i == n) && (j == 1 || j == m))
            res = 0;
        for (int ez = 0; ez < 2; ez++) {
            for (int vn = 0; vn < 2; vn++) {
                int dx = Math.abs(i - sx[ez]);
                int dy = Math.abs(j - sy[vn]);
                if (dx % a == 0 && dy % b == 0) {
                    int ta = dx / a;
                    int tb = dy / b;
                    // 奇偶性一致
                    if (ta % 2 == tb % 2) {
                        if (ta == 0 && (Math.abs(i - 1) < a) && (Math.abs(i - n) < a))
                            continue;
                        if (tb == 0 && (Math.abs(j - 1) < b) && (Math.abs(j - m) < b))
                            continue;
                        res = Math.min(res, Math.max(ta, tb));
                    }
                }
            }
        }
        if (res != Integer.MAX_VALUE)
            pw.println(res);
        else
            pw.println("Poor Inna and pony!");
        pw.close();
        br.close();
    }

}
