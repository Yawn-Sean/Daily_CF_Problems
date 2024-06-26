//算出斜线与两点的直线的四个交点，要么直接曼哈顿距离。要么就是产生的2*2=4种方案走斜线
//另一道羊蹄1 基环树 没看懂
import java.util.*;

public class d1032 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        double c = sc.nextDouble();
        double[] x = new double[10];
        double[] y = new double[10];
        x[1] = sc.nextDouble();
        y[1] = sc.nextDouble();
        x[2] = sc.nextDouble();
        y[2] = sc.nextDouble();
        double ans = Math.abs(x[1] - x[2]) + Math.abs(y[1] - y[2]);

        // 特殊情况：a 或 b 为 0 时，直线垂直于 x 轴或 y 轴
        if (a == 0) {
            ans = Math.min(ans, Math.abs(y[1] - (-c / b)) + Math.abs(y[2] - (-c / b)) + Math.abs(x[1] - x[2]));
        } else if (b == 0) {
            ans = Math.min(ans, Math.abs(x[1] - (-c / a)) + Math.abs(x[2] - (-c / a)) + Math.abs(y[1] - y[2]));
        } else { // 一般情况：a 和 b 均不为 0
            x[3] = x[1];
            y[3] = (-a * x[1] - c) / b;
            x[4] = (-b * y[1] - c) / a;
            y[4] = y[1];
            x[5] = x[2];
            y[5] = (-a * x[2] - c) / b;
            x[6] = (-b * y[2] - c) / a;
            y[6] = y[2];
            for (int i = 3; i <= 4; i++) {
                for (int j = 5; j <= 6; j++) {
                    ans = Math.min(ans, Math.abs(x[1] - x[i]) + Math.abs(y[1] - y[i]) +
                            Math.sqrt((x[i] - x[j]) * (x[i] - x[j]) + (y[i] - y[j]) * (y[i] - y[j])) +
                            Math.abs(x[2] - x[j]) + Math.abs(y[2] - y[j]));
                }
            }
        }
        System.out.printf("%.12f\n", ans);
    }
}
