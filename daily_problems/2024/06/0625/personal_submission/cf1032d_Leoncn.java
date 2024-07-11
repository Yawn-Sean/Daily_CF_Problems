
public class cf1032d_Leoncn {
        public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double x1 = sc.nextDouble();
        double y1 = sc.nextDouble();
        double x2 = sc.nextDouble();
        double y2 = sc.nextDouble();

        double ans = abs(x1 - x2) + abs(y1 - y2);

        List<double[]> points1 = findPoints(a, b, c, x1, y1);
        List<double[]> points2 = findPoints(a, b, c, x2, y2);

        double[] p1 = {x1, y1};
        double[] p2 = {x2, y2};

        for (double[] f1 : points1) {
            for (double[] f2 : points2) {
                ans = min(ans, distance(p1, f1) + distance(f1, f2) + distance(f2, p2));
            }
        }

        System.out.printf(Locale.US, "%.12f\n", ans);
    }

    private static List<double[]> findPoints(double a, double b, double c, double x, double y) {
        List<double[]> ans = new ArrayList<>();
        if (a != 0) ans.add(new double[] {-(b * y + c) / a, y});
        if (b != 0) ans.add(new double[] {x, -(a * x + c) / b});
        return ans;
    }

    private static double distance(double[] x, double[] y) {
        return sqrt(pow(x[0] - y[0], 2) + pow(x[1] - y[1], 2));
    }
}
