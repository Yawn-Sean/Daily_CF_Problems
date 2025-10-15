#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
int g[10][10];
string s;

int op(int x, int y) {
    memset(g, inf, sizeof(g));
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            g[i][(i+x)%10] = 1;
            g[i][(i+y)%10] = 1;
        }
    }
    for (int k = 0; k < 10; ++k) {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (g[i][k] != inf && g[k][j] != inf) {
                    g[i][j] = min(g[i][j], g[i][k]+g[k][j]);
                }
            }
        }
    }
    int ans = 0;
    for (int i = 1; i < s.length(); ++i) {
        int a = s[i-1] - '0', b = s[i] - '0';
        if (g[a][b] != inf) {
            ans += g[a][b] - 1;
        } else {
            return -1;
        }
    }
    return ans;
}

void solve() {
    cin >> s;
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            cout << op(i, j) << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
