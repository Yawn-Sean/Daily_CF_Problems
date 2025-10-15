#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;
int C[51][51];
void initC() {
    for (int i = 0; i <= 50; ++i) {
        C[i][0] = 1;
        for (int j = 1; j <= i; ++j) {
            C[i][j] = (C[i-1][j] + C[i-1][j-1]) % mod;
        }
    }
}

void solveC() {
    int n, k;
    cin >> n >> k;
    int a = 0, b = 0;
    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        if (x == 50) ++a;
        else ++b;
    }

    vector memo(n*5, vector(a+1, vector<pair<int, int>>(b+1, {1000, -1})));
    auto dfs = [&](auto &&self, int i, int x, int y) -> pair<int, int> {
        if (i >= 5 * n) return {1000, 0};
        if (x == 0 && y == 0) return {i, 1};
        if (memo[i][x][y].second != -1) return memo[i][x][y];
        int res = 1000, cnt = 0;
        int mxx = (i % 2 == 0 ? x : a - x), mxy = (i % 2 == 0 ? y : b - y);
        for (int xx = 0; xx * 50 <= k && xx <= mxx; ++xx) {
            for (int yy = 0; yy * 100 + xx * 50 <= k && yy <= mxy; ++yy) {
                if (xx == 0 && yy == 0) continue;
                auto [i2, cnt2] = self(self, i+1, x+((i&1)?1:-1)*xx, y+((i&1)?1:-1)*yy);
                cnt2 = 1LL * cnt2 * C[mxx][xx] % mod * C[mxy][yy] % mod;
                if (i2 < res) {
                    res = i2;
                    cnt = cnt2;
                } else if (i2 == res) {
                    cnt = (0LL + cnt + cnt2) % mod;
                }
            }
        }
        return memo[i][x][y] = {res, cnt};
    };

    auto [res, cnt] = dfs(dfs, 0, a, b);
    if (res == 1000) cout << "-1\n0";
    else cout << res << '\n' << cnt;
}

int main() {
    initC();
    solveC();
    return 0;
}
