#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using pii = std::pair<int, int>;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    vector<string> board(n);
    for (int i = 0; i < n; ++i) {
        cin >> board[i];
    }

    vector<vector<int>> diff(n + 1, vector<int>(n + 1));
    int WL{0};

    for (int i = 0; i < n; ++i) {
        int mi = n;
        int mx = -1;
        for (int j = 0; j < n; ++j) {
            if (board[i][j] == 'B') {
                mi = min(mi, j);
                mx = max(mx, j);
            }
        }
        if (mi > mx) { 
            WL++; 
        } else if (mx - mi + 1 <= k) {
            int x_u = max(0, i - k + 1);
            int x_d = i;
            int y_l = max(0, mx - k + 1);
            int y_r = mi;
            diff[x_u][y_l]++;
            diff[x_d + 1][y_l]--;
            diff[x_u][y_r + 1]--;
            diff[x_d + 1][y_r + 1]++;
        }
    }

    for (int j = 0; j < n; ++j) {
        int mi = n;
        int mx = -1;
        for (int i = 0; i < n; ++i) {
            if (board[i][j] == 'B') {
                mi = min(mi, i);
                mx = max(mx, i);
            }
        }
        if (mi > mx) { 
            WL++; 
        } else if (mx - mi + 1 <= k) {
            int x_u = max(0, mx - k + 1);
            int x_d = mi;
            int y_l = max(0, j - k + 1);
            int y_r = j;
            diff[x_u][y_l]++;
            diff[x_d + 1][y_l]--;
            diff[x_u][y_r + 1]--;
            diff[x_d + 1][y_r + 1]++;
        }
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= n; ++j) {
            diff[i + 1][j] += diff[i][j];
        }
    }

    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j < n; ++j) {
            diff[i][j + 1] += diff[i][j];
        }
    }

    int ret = 0;
    for (int i = 0; i < n; ++i) {
        ret = max(ret, *max_element(begin(diff[i]), end(diff[i])));
    }

    cout << ret + WL << endl;

    return 0;
}