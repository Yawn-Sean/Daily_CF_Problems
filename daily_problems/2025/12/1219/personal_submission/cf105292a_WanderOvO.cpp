#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;

const int N = 2010;

/*
暴力枚举位置，然后能放就放即可
每个位置只被访问常数次，所以复杂度正确
*/

string grid[N];

void solve() {
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.') {
                grid[i][j] = 'L'; 
                for (int x = i + 1; x < n; x++) {
                    if (grid[x][j] == '#') {
                        break;
                    }
                    grid[x][j] = '*'; 
                }
                for (int y = j + 1; y < m; y++) {
                    if (grid[i][y] == '#') {
                        break;
                    }
                    grid[i][y] = '*'; 
                }
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '*') {
                grid[i][j] = '.';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << grid[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T = 1;
    cin >> T;
    while (T--) {
        solve();    
    }

    return 0;
}
