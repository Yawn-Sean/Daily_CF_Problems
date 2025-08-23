import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int m = Integer.parseInt(st.nextToken());
        int[] d = new int[m], h = new int[m];
        int res = 0;
        for (int ez = 0; ez < m; ez++) {
            st = new StringTokenizer(br.readLine());
            d[ez] = Integer.parseInt(st.nextToken());
            h[ez] = Integer.parseInt(st.nextToken());
            if (ez > 0) {
                int cha = d[ez] - d[ez - 1], tmp = Math.abs(h[ez] - h[ez - 1]);
                if (cha < tmp) {
                    pw.print("IMPOSSIBLE");
                    pw.close();
                    return;
                }
                res = Math.max(res, Math.max(h[ez], h[ez - 1]) + (cha - tmp) / 2);
            } else
                res = d[ez] + h[ez] - 1;
        }
        res = Math.max(res, n - d[m - 1] + h[m - 1]);
        pw.println(res);
        pw.close();
    }

}
