import java.util.*;
import java.io.*;
public class B {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int u = sc.nextInt();
        double[] g = new double[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }
        double ans = -1;
        int to = 0;
        for (int from = 0; from < n; from++) {
            while (to + 1 < n && g[to + 1] - g[from] <= u) {
                to++;
            }
            if (to - from >= 2) {
                double kpd = (g[to] - g[from + 1]) / (g[to] - g[from]);
                ans = Math.max(ans, kpd);
            }
        }
        System.out.println(ans);
    }
}