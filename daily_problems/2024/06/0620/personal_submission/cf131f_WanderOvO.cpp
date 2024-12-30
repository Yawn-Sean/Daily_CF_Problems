/*
对于每个点，预处理看上下左右是否符合题意，符合则标为 1，前缀和统计
枚举矩形，假如一个较小的矩形符合要求，则更大的矩形就都符合要求，可以直接统计上
一共 250000 个点，所以有 250000^2 个矩形
枚举左上角，枚举右下角的行，二分列
*/

int T;
char s[N][N];
int n, m, target;
int pre[N][N], dx[4] = {0, 0, 1, -1}, dy[4] = {1, -1, 0, 0};

void solve1() {
    scanf("%d %d %d", &n, &m, &target);
    for (int i = 1; i <= n; i++) {
        scanf("%s", s[i] + 1);
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (s[i][j] == '0') continue;
            int cnt = 0;
            for (int k = 0; k < 4; k++) {
                if (i + dx[k] > 0 && i + dx[k] <= n && j + dy[k] > 0 && j + dy[k] <= m) {
                    if (s[i + dx[k]][j + dy[k]] == '1') {
                        cnt++;
                    }
                }
            }
            if (cnt == 4) {
                pre[i][j] = 1;
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            pre[i][j] += pre[i - 1][j] + pre[i][j - 1] - pre[i - 1][j - 1];
        }
    }

    LL res = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            for (int u = i + 2; u <= n; u++) {
                int l = j + 2, r = m, mid;
                // 左上角 (i, j)，右下角 (u, mid)
                // 要考虑中心在 (i + 1, j + 1) 到 (u - 1, mid - 1) 范围内的
                while (l + 1 < r) {
                    mid = (l + r) / 2;
                    int cnt = pre[u - 1][mid - 1] - pre[i][mid - 1] - pre[u - 1][j] + pre[i][j];
                    if (cnt >= target) {
                        r = mid;
                    } else {
                        l = mid;
                    }
                }
                int cnt1 = pre[u - 1][l - 1] - pre[i][l - 1] - pre[u - 1][j] + pre[i][j];
                int cnt2 = pre[u - 1][r - 1] - pre[i][r - 1] - pre[u - 1][j] + pre[i][j];
                if (cnt1 >= target) {
                    res += (m - l + 1);
                } else if (cnt2 >= target) {
                    res += (m - r + 1);
                } 
            }
        }
    }
    cout << res << "\n";
}      