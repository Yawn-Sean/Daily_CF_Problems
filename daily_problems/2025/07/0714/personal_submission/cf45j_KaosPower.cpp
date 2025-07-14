#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    if (n + m > 2 && n + m < 5) cout << -1;
    else {
        vector<vector<int>> grid(n, vector<int>(m));
        int pt = 0;

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2) {
                    grid[i][j] = ++pt;
                }
            }
        }

        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < m; j ++) {
                if ((i + j) % 2 == 0) {
                    grid[i][j] = ++pt;
                }
            }
        }

        for (auto &x: grid) {
            for (auto &y: x) {
                cout << y << ' ';
            }
            cout << '\n';
        }
    }

    return 0;
}
