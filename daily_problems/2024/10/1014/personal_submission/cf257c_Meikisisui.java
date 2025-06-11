import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Test2 {

    public static void main(String[] args) throws IOException {
        BufferedReader f = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw = new PrintWriter(System.out);
        StringTokenizer st = new StringTokenizer(f.readLine());
        int n = Integer.parseInt(st.nextToken());
        double[] t = new double[n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(f.readLine());
            int x = Integer.parseInt(st.nextToken());
            int y = Integer.parseInt(st.nextToken());
            t[i] = Math.atan2(y, x);
        }
        Arrays.sort(t);
        double res = 0;
        for (int i = 0; i < n; i++) {
            double a = (Math.abs(t[i] - t[(i + 1) % n]));
            if (i == n - 1)
                a = 2 * Math.PI - a;
            res = Math.max(res, a);
        }
        pw.println(360 - res * 360 / (2 * Math.PI));
        pw.close();
        f.close();
    }

}
