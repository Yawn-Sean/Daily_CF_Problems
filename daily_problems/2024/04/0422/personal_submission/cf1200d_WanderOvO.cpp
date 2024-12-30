/*
选一个地方点，其最多影响 k 行和 k 列
如果某行的最左边的 B 和最右边的 B 的格子数 <= k，则这一行有可能变成全 W
并且我们能算出来点哪些区域的时候能让这一行/列变成全白，这个区域肯定是一个矩形
我们维护一个差分数组，假如对于第 i 行/列，点击 (x1, y1) 到 (x2, y2) 组成的矩形中的某个点能全白，则加上去
最后求差分数组的和，取最大的那个即可
*/

int T;
int n, k;
char a[N][N];
int d[N][N];

void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> (a[i] + 1);
    }
    
    for (int i = 1; i <= n; i++) {
        int left_b = 0, right_b = 0;
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == 'B') {
                if (left_b == 0) {
                    left_b = right_b = j;
                } else {
                    right_b = j;
                }
            }
        }
        if (right_b - left_b + 1 > k) {
            continue;
        }
        if (left_b == 0) {
            d[1][1]++;
            continue;
        }
        int x1, y1, x2 = i, y2 = left_b;
        x1 = max(1, i - k + 1);
        y1 = max(1, right_b - k + 1);
        d[x1][y1]++;
        d[x1][y2 + 1]--;
        d[x2 + 1][y1]--;
        d[x2 + 1][y2 + 1]++;
    }
    
    for (int j = 1; j <= n; j++) {
        int left_b = 0, right_b = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i][j] == 'B') {
                if (left_b == 0) {
                    left_b = right_b = i;
                } else {
                    right_b = i;
                }
            }
        }
        if (right_b - left_b + 1 > k) {
            continue;
        }
        if (left_b == 0) {
            d[1][1]++;
            continue;
        }
        int x1, y1, x2 = left_b, y2 = j;
        x1 = max(1, right_b - k + 1);
        y1 = max(1, j - k + 1);
        d[x1][y1]++;
        d[x1][y2 + 1]--;
        d[x2 + 1][y1]--;
        d[x2 + 1][y2 + 1]++;
    }
    
    int res = 0;
    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            d[i][j] += (d[i - 1][j] + d[i][j - 1] - d[i - 1][j - 1]);
            // cout << d[i][j] << " ";
            res = max(res, d[i][j]);
        }
        // cout << "\n";
    }
    cout << res;
}      