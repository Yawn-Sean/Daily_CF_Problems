import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) {
        FastReader fr = new FastReader();
        PrintWriter out = new PrintWriter(System.out);
        int n = fr.nextInt();
        double[] angles = new double[n];
        for (int i = 0; i < n; i++) {
            int x = fr.nextInt();
            int y = fr.nextInt();
            angles[i] = Math.atan2(y, x);
        }

        Arrays.sort(angles);
        double ans = 0.0;
        double pi = Math.atan2(0, -1);
        for (int i = 1; i < n; i++) {
            ans = Math.max(ans, angles[i] - angles[i - 1]);
        }
        double result = Math.min(2 * pi - ans, angles[n - 1] - angles[0]) / pi * 180;
        out.printf("%.20f", result);
        out.close();
    }
}
