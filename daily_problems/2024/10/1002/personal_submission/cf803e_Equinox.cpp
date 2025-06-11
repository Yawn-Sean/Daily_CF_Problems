#include <bits/stdc++.h>

// #define DEBUG

using u32 = unsigned;
using i64 = long long;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;


void solve() {
    int n, k;
    std::cin >> n >> k;

    std::string s;
    std::cin >> s;

    std::map<char, std::vector<int>> st;

    st['L'] = { -1 };
    st['W'] = { 1 };
    st['D'] = { 0 };
    st['?'] = std::vector<int>{ -1, 0, 1 };

    std::vector<std::vector<int>> f(n + 1, std::vector<int>(2 * k + 1, inf32));

    f[0][k] = 0;

    for (int i = 0; i < n; ++ i) {
        for (int v : st[s[i]]) {
            for (int j = 1; j < 2 * k; ++ j) {
                if (f[i][j] != inf32)
                    f[i + 1][j + v] = v;
            }
        }
    }

    if (f[n][0] == inf32 && f[n][2 * k] == inf32) {
        std::cout << "NO\n";
        return;
    }

    std::map<int, char> rst;

    rst[-1] = 'L';
    rst[1] = 'W';
    rst[0] = 'D';


    //restore
    std::string res;

    for (int i = n, cur = f[n][0] == inf32 ? 2 * k : 0; i; -- i) {
        assert(0 <= cur && cur <= 2 * k);
        res.push_back(rst[f[i][cur]]);
        cur -= f[i][cur];
    }

    std::reverse(res.begin(), res.end());

    std::cout << res << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

#ifdef DEBUG
    int cur = clock();
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int t = 1;
    // std::cin >> t;

    while (t--) {
        solve();
    }
#ifdef DEBUG
    std::cerr << "run-time: " << clock() - cur << '\n';
#endif
    return 0;
}