import java.io.*;
import java.util.StringTokenizer;

public class Test3 {

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] a = new int[n];
        st = new StringTokenizer(br.readLine());
        for (int ez = 0; ez < n; ez++)
            a[ez] = Integer.parseInt(st.nextToken());
        long res = Long.MAX_VALUE, tmp = 0, cur = a[0];
        for (int ez = 1; ez < n; ez++) {
            if ((ez & 1) == 1) {
                cur = Math.max(cur + 1, a[ez]);
                tmp += cur - a[ez];
            } else {
                cur = Math.min(cur - 1, a[ez]);
                tmp += a[ez] - cur;
            }
        }
        res = Math.min(res, tmp);
        tmp = 0;
        cur = a[0];
        for (int ez = 1; ez < n; ez++) {
            if ((ez & 1) == 1) {
                cur = Math.min(cur - 1, a[ez]);
                tmp += a[ez] - cur;
            } else {
                cur = Math.max(cur + 1, a[ez]);
                tmp += cur - a[ez];
            }
        }
        res = Math.min(res, tmp);
        pw.println(res);
        pw.close();
    }

}
