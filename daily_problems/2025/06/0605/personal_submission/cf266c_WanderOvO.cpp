/*
我的构造方法：
1. 将第 n 列和第 1 行转化成全 0，这一定可以做到
2. 只考虑左下角的 (n - 1) * (n - 1) 的方阵，相当于将所有的 1 移动到这个方阵的主对角线以及之下
3. 将 (n - 1) * (n - 1) 方阵中全为 0 的列移动到右边
4. 将 (n - 1) * (n - 1) 方阵中所有的行排序，以行中列号最大的 1 为排序关键字，升序排序
5. 按照上面的顺序枚举行，假设这一行的 1 的最大列是 j，则这行至少放在第 j 行
6. 如果第 j 行被占用了，则依次往下顺延
麻烦，不想写

更巧妙的做法：转化为规模更小的问题
把 n * n 有至多 n - 1 个 1 的问题，转化为 (n - 1) * (n - 1) 至多有 n - 2 个 1 的问题
每次只需要把一个全为 0 的列移动到右边，然后把一个至少包含 1 个 1 的行移动到最下面即可
如果移动不了了，说明已经结束了
*/

struct Operation {
    int op, i, j;
};

int n;
int grid[M][M], cnt_r[M], cnt_c[M];

void meibao() {
    cin >> n;
    memset(grid, 0, sizeof grid);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        grid[x][y]++;
        cnt_r[x]++;
        cnt_c[y]++;
    }
    vector<Operation> res;
    for (int rd = 1; rd < n; rd++) {
        for (int i = 1; i <= n - rd; i++) {
            if (cnt_c[i] == 0) {
                res.push_back({2, i, n - rd + 1});
                for (int j = 1; j <= n; j++) {
                    swap(grid[j][i], grid[j][n - rd + 1]);
                }
                cnt_c[i] = 0;
                for (int j = 1; j <= n - rd + 1; j++) {
                    cnt_c[i] += grid[j][i];
                }
                break;
            }
        }

        for (int i = 1; i <= n - rd; i++) {
            if (cnt_r[i] > 0) {
                res.push_back({1, i, n - rd + 1});
                for (int j = 1; j <= n; j++) {
                    swap(grid[i][j], grid[n - rd + 1][j]);
                }
                cnt_r[i] = 0;
                for (int j = 1; j <= n - rd + 1; j++) {
                    cnt_r[i] += grid[i][j];
                }
                break;
            }
        }

        for (int j = 1; j <= n - rd; j++) {
            cnt_r[j] -= grid[j][n - rd + 1];
            cnt_c[j] -= grid[n - rd + 1][j];
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << grid[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    cout << res.size() << "\n";
    for (auto op : res) {
        cout << op.op << " " << op.i << " " << op.j << "\n";
    }
}
