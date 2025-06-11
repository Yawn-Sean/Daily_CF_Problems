#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int>> a(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    /*
    对于a[i][j] 位置 第j列 往上能到哪里 往下能到哪里
    然后对于j-1,j-2,... 直到变成a[i][j'] = 0
    对于j+1,j+2,... 直到变成a[i][j'] = 0

    这些列的像素屏幕=1的行上下限 l[j],r[j]

    得到了这些信息后就能计算最大矩形面积
    */
    
    vector<vector<int>> left(n, vector<int>(m));
    vector<vector<int>> right(n, vector<int>(m));
    vector<vector<int>> up(n, vector<int>(m));
    vector<vector<int>> down(n, vector<int>(m));

    // 向左/向右/向上/向下的最长1
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 1) {
                left[i][j] = 1;
                right[i][j] = 1;
                up[i][j] = 1;
                down[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j]) {
                if (j > 0) {
                    left[i][j] += left[i][j - 1];
                }
                if (i > 0) {
                    up[i][j] += up[i - 1][j];
                }
            }
        }
    } 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (a[i][j]) {
                if (j < m - 1) {
                    right[i][j] += right[i][j + 1];
                }
                if (i < n - 1) {
                    down[i][j] += down[i + 1][j];
                }
            }
        }
    }

    while (q--) {
        int op, x, y;
        cin >> op >> x >> y;
        x--;
        y--;
        if (op == 1) {
            a[x][y] = 1 - a[x][y];
            for (int i = 0; i < m; i++) {
                if (a[x][i]) {
                    left[x][i] = 1;
                    if (i > 0) {
                        left[x][i] += left[x][i - 1];
                    } 
                } else {
                    left[x][i] = 0;
                }
            }
            for (int i = m - 1; i >= 0; i--) {
                if (a[x][i]) {
                    right[x][i] = 1;
                    if (i < m - 1) {
                        right[x][i] += right[x][i + 1];
                    }
                } else {
                    right[x][i] = 0;
                }
            }

            for (int i = 0; i < n; i++) {
                if (a[i][y]) {
                    up[i][y] = 1;
                    if (i > 0) {
                        up[i][y] += up[i - 1][y];
                    }
                } else {
                    up[i][y] = 0;
                }
            }
            for (int i = n - 1; i >= 0; i--) {
                if (a[i][y]) {
                    down[i][y] = 1;
                    if (i < n - 1) {
                        down[i][y] += down[i + 1][y];
                    }
                } else {
                    down[i][y] = 0;
                }
            }

        } else {
            int ans = 0;
            
            int l, r, cur;
            l = x;
            r = x;
            cur = left[x][y];
            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == n - 1) {
                    break;
                }

                if (l == 0) {
                    cur = min(cur, left[++r][y]);
                } else if (r == n - 1) {
                    cur = min(cur, left[--l][y]);
                } else if (left[l - 1][y] > left[r + 1][y]) {
                    cur = min(cur, left[--l][y]);
                } else {
                    cur = min(cur, left[++r][y]);
                }
            }

            l = x;
            r = x;
            cur = right[x][y];
            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == n - 1) {
                    break;
                }

                if (l == 0) {
                    cur = min(cur, right[++r][y]);
                } else if (r == n - 1) {
                    cur = min(cur, right[--l][y]);
                } else if (right[l - 1][y] > right[r + 1][y]) {
                    cur = min(cur, right[--l][y]);
                } else {
                    cur = min(cur, right[++r][y]);
                }
            }

            l = y;
            r = y;
            cur = up[x][y];
            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == m - 1) {
                    break;
                }

                if (l == 0) {
                    cur = min(cur, up[x][++r]);
                } else if (r == m - 1) {
                    cur = min(cur, up[x][--l]);
                } else if (up[x][l - 1] > up[x][r + 1]) {
                    cur = min(cur, up[x][--l]);
                } else {
                    cur = min(cur, up[x][++r]);
                }
            }

            l = y;
            r = y;
            cur = down[x][y];
            while (true) {
                ans = max(ans, cur * (r - l + 1));
                if (r - l == m - 1) {
                    break;
                }
                if (l == 0) {
                    cur = min(cur, down[x][++r]);
                } else if (r == m - 1) {
                    cur = min(cur, down[x][--l]);
                } else if (down[x][l - 1] > down[x][r + 1]) {
                    cur = min(cur, down[x][--l]);
                } else {
                    cur = min(cur, down[x][++r]);
                }
            }  
            cout << ans << '\n';
        }
    }
    return 0;
}
