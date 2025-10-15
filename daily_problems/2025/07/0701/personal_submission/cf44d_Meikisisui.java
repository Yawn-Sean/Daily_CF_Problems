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
        Point[] P = new Point[n + 1];
        for (int ez = 1; ez <= n; ez++) {
            st = new StringTokenizer(br.readLine());
            double x = Double.parseDouble(st.nextToken());
            double y = Double.parseDouble(st.nextToken());
            double z = Double.parseDouble(st.nextToken());
            P[ez] = new Point(x, y, z);
        }
        double res = Double.MAX_VALUE;
        for (int ez = 2; ez <= n; ez++) {
            for (int vn = ez + 1; vn <= n; vn++) {
                double currentDist = dist(P[1], P[ez]) + dist(P[1], P[vn]) + dist(P[ez], P[vn]);
                res = Math.min(res, currentDist);
            }
        }
        pw.printf("%.10f\n", res / 2.0);
        pw.close();
        br.close();
    }

    private static class Point {
        double x, y, z;

        Point(double x, double y, double z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }
    }

    private static double dist(Point a, Point b) {
        return Math.sqrt((a.x - b.x) * (a.x - b.x) +
                (a.y - b.y) * (a.y - b.y) +
                (a.z - b.z) * (a.z - b.z));
    }

}
