#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    vector<vector<int>> grid(n, vector<int>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> grid[i][j];
        }
    }

    int maxv = n * n + 1;
    vector<vector<int>> saved(n, vector<int>(n * n + 1, maxv));

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            for (int k = 0; k < n; ++k) {
                if (i + k >= n || j + k >= n) break;
                saved[k][grid[i][j]] = min(saved[k][grid[i][j]], grid[i + k][j + k]);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = n * n - 1; j >= 0; --j) {
            saved[i][j] = min(saved[i][j], saved[i][j + 1]);
        }
    }

    while (q--) {
        int a, b;
        cin >> a >> b;

        for (int i = n - 1; i >= 0; --i) {
            if (saved[i][a] <= b) {
                cout << 1LL * (i + 1) * (i + 1) << '\n';
                break;
            }
        }
    }

    return 0;
}
