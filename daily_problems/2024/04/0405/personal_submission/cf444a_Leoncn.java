import java.util.Scanner;

/**
 * @Description:
 * @Author: Leon
 * @Date: 2024/4/6
 */
public class A {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] g = new int[n];
        for (int i = 0; i < n; i++) {
            g[i] = sc.nextInt();
        }
        double ans = 0;
        for (int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int c = sc.nextInt();
            ans = Math.max((double)(g[a-1] + g[b-1])/c, ans);

        }
        System.out.println(ans);
    }
}
