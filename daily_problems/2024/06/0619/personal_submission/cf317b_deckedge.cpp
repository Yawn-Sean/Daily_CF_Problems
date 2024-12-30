#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin() + 1, (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), t = red();
    ve grid(151, ve<int>(151));
    
    grid[75][75] = n;
    int dir[4][2] = {
        {0, 1},
        {1, 0},
        {0, -1},
        {-1, 0}
    };
    bool found = true;
    while (found) {
        found = false;
        rep(i, 0, 151) {
            rep(j, 0, 151) {
                if (grid[i][j] >= 4) {
                    int val = grid[i][j] / 4;
                    grid[i][j] %= 4;
                    rep(k, 0, 4) {
                        int dx = i + dir[k][0], dy = j + dir[k][1];
                        grid[dx][dy] += val;
                        found = true;
                    }
                }

            }
        }
    }
    while (t--) {
        int x = red(), y = red();
        if (abs(x) > 75 || abs(y) > 75) {
            cout << "0\n";
        } else {
            x += 75;
            y += 75;
            cout << grid[x][y] << '\n';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}