import java.util.Scanner;

public class cf1073c_yuxue_r {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        // 读取输入
        int n = scanner.nextInt();
        String s = scanner.next();
        int x = scanner.nextInt();
        int y = scanner.nextInt();

        // 定义方向映射
        int[][] dirs = {
                {'U', 0, 1},
                {'D', 0, -1},
                {'L', -1, 0},
                {'R', 1, 0}
        };

        // 检查可行性
        if (Math.abs(x) + Math.abs(y) > n || (x + y - n) % 2 != 0) {
            System.out.println(-1);
        } else {
            int[] acc_x = new int[n + 1];
            int[] acc_y = new int[n + 1];

            // 计算累积坐标
            for (int i = 0; i < n; i++) {
                char ch = s.charAt(i);
                int dx = 0, dy = 0;
                for (int[] dir : dirs) {
                    if (dir[0] == ch) {
                        dx = dir[1];
                        dy = dir[2];
                        break;
                    }
                }
                acc_x[i + 1] = acc_x[i] + dx;
                acc_y[i + 1] = acc_y[i] + dy;
            }

            // 定义检查函数
            int ans = n + 1;
            int l = 0, r = 0;
            while (l <= n) {
                while (r < n && check(acc_x, acc_y, l, r, x, y, n)) {
                    r += 1;
                }
                if (check(acc_x, acc_y, l, r, x, y, n)) {
                    break;
                }
                ans = Math.min(ans, r - l);
                l += 1;
            }

            System.out.println(ans);
        }
    }

    private static boolean check(int[] acc_x, int[] acc_y, int l, int r, int x, int y, int n) {
        return Math.abs(acc_x[l] + acc_x[n] - acc_x[r] - x) + Math.abs(acc_y[l] + acc_y[n] - acc_y[r] - y) > r - l;
    }
}
