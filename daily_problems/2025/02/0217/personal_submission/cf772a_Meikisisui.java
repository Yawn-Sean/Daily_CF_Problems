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
        int p = Integer.parseInt(st.nextToken());
        int[] a = new int[n], b = new int[n];
        long sum = 0;
        for (int ez = 0; ez < n; ez++) {
            st = new StringTokenizer(br.readLine());
            a[ez] = Integer.parseInt(st.nextToken());
            sum += a[ez];
            b[ez] = Integer.parseInt(st.nextToken());
        }
        if (p >= sum) {
            pw.println("-1");
            pw.close();
            br.close();
            return;
        }
        double left = 0, right = 1e10 + 1, res = 0;
        int cnt = 0;
        while (cnt < 1000) {
            double mid = left + (right - left) / 2;
            if (checkMid(mid, a, b, p)) {
                left = mid;
                res = mid;
            } else
                right = mid;
            cnt++;
        }
        pw.print(res);
        pw.close();
        br.close();
    }

    private static boolean checkMid(double mid, int[] a, int[] b, int p) {
        double time = p * mid;
        for (int ez = 0; ez < a.length; ez++) {
            if ((double) a[ez] * mid > (double) b[ez])
                time -= (double) a[ez] * mid - (double) b[ez];
        }
        if (time >= 0)
            return true;
        else
            return false;
    }

}
