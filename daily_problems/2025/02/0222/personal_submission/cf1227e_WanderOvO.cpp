/*
一层一层向外扩展的，并且注意题目限制矩阵外的部分都没有被点燃！
二分最大的时间，假设为 t，则枚举所有的边长为 2 * t + 1 的正方形，假如全都是着火的地方，则中心必然存在一个自燃点
找到所有自燃点之后，前缀和算起来，检查和目标矩阵是否一致，一致才是合理的
可以想象到，t 越大，越容易有的地方覆盖不到，导致比起来不一致；t 小的时候，可以通过几个小的拼起来达成大的效果
0 是一定行的，所以一定有解
*/

int n, m;

bool check(int ans, vector<vector<int>> &grid) {
    vector<vector<int>> acc_grid(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> d(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            acc_grid[i][j] = grid[i][j] + acc_grid[i - 1][j] + acc_grid[i][j - 1] - acc_grid[i - 1][j - 1]; 
        }
    }

    for (int i = 1; i + 2 * ans <= n; i++) {
        for (int j = 1; j + 2 * ans <= m; j++) {
            int k = i + 2 * ans, l = j + 2 * ans;
            int sum = acc_grid[k][l] - acc_grid[i - 1][l] - acc_grid[k][j - 1] + acc_grid[i - 1][j - 1];
            if (sum == (2 * ans + 1) * (2 * ans + 1)) {
                d[i][j]++;
                d[i][l + 1]--;
                d[k + 1][j]--;
                d[k + 1][l + 1]++;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            d[i][j] += d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1];
            if (grid[i][j] > 0 && d[i][j] == 0) {
                return false;
            }
            if (grid[i][j] == 0 && d[i][j] > 0) {
                return false;
            }
        }
    }
    return true;
}

void construct_matrix(int ans, vector<vector<int>> &grid) {
    vector<vector<int>> acc_grid(n + 2, vector<int>(m + 2, 0));
    vector<vector<int>> d(n + 2, vector<int>(m + 2, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            acc_grid[i][j] = grid[i][j] + acc_grid[i - 1][j] + acc_grid[i][j - 1] - acc_grid[i - 1][j - 1]; 
        }
    }

    for (int i = 1; i + 2 * ans <= n; i++) {
        for (int j = 1; j + 2 * ans <= m; j++) {
            int k = i + 2 * ans, l = j + 2 * ans;
            int sum = acc_grid[k][l] - acc_grid[i - 1][l] - acc_grid[k][j - 1] + acc_grid[i - 1][j - 1];
            if (sum == (2 * ans + 1) * (2 * ans + 1)) {
                d[i + ans][j + ans] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (d[i][j] == 0) {
                cout << ".";
            } else {
                cout << "X";
            }
        }
        cout << "\n";
    }
}

void meibao() {
    cin >> n >> m;
    vector<vector<int>> grid(n + 2, vector<int>(m + 2));
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == '.') {
                grid[i][j + 1] = 0;
            } else {
                grid[i][j + 1] = 1;
            }
        }
    } 

    int l = 0, r = (min(n, m) - 1) / 2, mid;
    while (l + 1 < r) {
        mid = l + (r - l) / 2;
        if (check(mid, grid)) {
            l = mid;
        } else {
            r = mid;
        }
    }
    int res;
    if (check(r, grid)) {
        res = r;
    } else {
        res = l;
    }   

    cout << res << "\n";
    construct_matrix(res, grid);
}
