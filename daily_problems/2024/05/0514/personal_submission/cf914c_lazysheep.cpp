#include <bits/stdc++.h>

using namespace std;
using i64 = int64_t;

const int MOD = 1e9 + 7, N = 1010;

int cnt[N], f[N][N][2];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k, ans = 0;
    string s;
    cin >> s >> k;
    memset(f, -1, sizeof f);
    if (k == 0) {
        cout << 1 << '\n';
        return 0;
    }
    n = s.size();

    function<int(int, int, bool)> dfs = [&](int id, int cnt, bool lim) -> int {
        if (id == n) return cnt == 0;
        if (n - id < cnt)   return 0;
        int& res = f[id][cnt][lim];
        if (res != -1)   return res;
        res = 0;
        int up = lim ? s[id] - '0' : 1;
        for (int i = 0; i <= up; i++) {
            res = ((i64)dfs(id + 1, cnt - i, lim && i == up) + res) % MOD;
        }
        return res;
    };

    for (int i = 2; i <= 1000; i++) {
        int c = __builtin_popcount(i);
        cnt[i] = cnt[c] + 1;       
    }
    for (int i = 1; i <= 1000; i++) {
        if (cnt[i] == k - 1) {
            ans = ((i64) ans + dfs(0, i, true)) % MOD;
            if (i == 1) ans -= 1;
        }
    }

    cout << ans << '\n';

    return 0;
}
