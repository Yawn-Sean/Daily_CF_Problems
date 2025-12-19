#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            grid[i][j] = (s[j] == '.') ? 0 : 1;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == 0) {
                grid[i][j] = 2;

                for (int ni = i + 1; ni < n; ni++) {
                    if (grid[ni][j] == 1) break;
                    grid[ni][j] = 3;
                }

                for (int nj = j + 1; nj < m; nj++) {
                    if (grid[i][nj] == 1) break;
                    grid[i][nj] = 3;
                }
            }
        }
    }

    string mp = " #L.";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mp[grid[i][j]];
        }
        cout << '\n';
    }

    return 0;
}
