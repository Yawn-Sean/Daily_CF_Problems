/*
检查中间行附近是否有突变，假如突变点大于一定的比例，就是翻转了
我设置只要中间那两行的差值 > 10 就认为是突变，突变的点的比例超过一半就是翻转
*/

int n, m;
int grid[N][N];
 
void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> grid[i][j];
        }
    }

    if (n % 2 == 0) {
        int r1 = n / 2, r2 = r1 + 1;
        int max_d = 10;
        int cnt = 0;
        double max_rate = 0.5;
        for (int i = 1; i <= m; i++) {
            int d = abs(grid[r1][i] - grid[r2][i]);
            if (d > max_d) {
                cnt++;
            }
        }
        double rate = (1.0 * cnt) / m;
        if (rate > max_rate) {
            cout << "print(\"YES\")" << "\n";
        } else {
            cout << "print(\"NO\")\n";
        }
    } else {
        cout << "print(\"NO\")\n";
    }
}   
