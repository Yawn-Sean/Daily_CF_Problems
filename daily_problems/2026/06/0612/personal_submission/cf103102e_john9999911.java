// 378269858

    static void solve() {
        int n = io.nextInt();
        long res = 0;
        // f_x_y 表示sum%3,sq_sum%3的情况个数
        int[][] f = new int[3][3];
        f[0][0] = 1;
        int sum = 0, sq_sum = 0;
        while (n-- > 0) {
            int v = io.nextInt() % 3;
            sum = (sum + v) % 3;
            sq_sum = (sq_sum + v * v) % 3;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    int t_sum = (sum - i) % 3;
                    int t_sq_sum = (sq_sum - j) % 3;
                    if ((t_sum * t_sum - t_sq_sum) % 3 == 0) {
                        res += f[i][j];
                    }
                }
            }
            f[sum][sq_sum]++;
        }
        io.println(res);
    }