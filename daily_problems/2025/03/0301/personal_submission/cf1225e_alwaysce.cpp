#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
    可以拆成一系列的-> 和 ↓过程 交替出现
    1. 走到(i,j)位置的时候 下一步i+1/j+1
    2. 已经走过的行/列不会有任何影响 可以去掉
    3. 石头阻挡了-> 或者 ↓ 的可行距离长度
    
    i-> (n - 1 -acc[i+1][j] + 1)正好是下一个位置
    这些-> 都会加上 之前↓ 的可行方案
    同理对于↓
    */
    
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (auto&s: grid) { cin >> s; }

    if (grid[0][0] == 'R' || grid[n - 1][m - 1] == 'R') {
        cout << 0;
        return 0;
    }
    if (n == 1 && m == 1) {
        cout << 1;
        return 0;
    }

    vector<vector<int>> acc_h(n, vector<int>(m + 1, 0));
    vector<vector<int>> acc_v(n + 1, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 'R') {
                acc_h[i][j] = 1;
                acc_v[i][j] = 1;
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 0; j < m; j++) {
            acc_v[i][j] += acc_v[i + 1][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = m - 2; j >= 0; j--) {
            acc_h[i][j] += acc_h[i][j + 1];
        }
    }

    vector<vector<i64>> diff_h(n, vector<i64>(m + 1, 0));
    vector<vector<i64>> diff_v(n + 1, vector<i64>(m, 0));

    diff_h[0][0] = 1;
    diff_h[0][1] = -1;
    diff_v[0][0] = 1;
    diff_v[1][0] = -1;


    vector<i64> ans_h(n, 0);
    vector<i64> ans_v(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            ans_h[i] += diff_h[i][j];
            ans_v[j] += diff_v[i][j];
            
            // 累加之前->
            diff_h[i][j + 1] = (diff_h[i][j + 1] + ans_v[j]) % mod;
            int nxt = m - acc_h[i][j + 1];
            diff_h[i][nxt] = (diff_h[i][nxt] - ans_v[j] + mod) % mod;
            
            // 累加之前↓
            diff_v[i + 1][j] = (diff_v[i + 1][j] + ans_h[i]) % mod;
            nxt = n - acc_v[i + 1][j];
            diff_v[nxt][j] = (diff_v[nxt][j] - ans_h[i] + mod) % mod;
        }
    }

    cout << (ans_h[n - 1] + ans_v[m - 1]) % mod << '\n';
    return 0;
}
