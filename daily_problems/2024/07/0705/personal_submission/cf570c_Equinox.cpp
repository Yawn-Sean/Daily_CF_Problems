#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e9 + 7, P = 998244353;

void solve() {
    int n, m;
    std::cin >> n >> m;
    std::string s;
    std::cin >> s;
    std::vector<int> a(n + 2);
    for (int i = 0; i < n; i ++ )
        if (s[i] == '.') a[i + 1] = 1;
    int f = 0, con = 0;
    for (int x : a)
        if (x) ++ con;
        else {
            if (con) f += con - 1;
            con = 0;
        }
    for (int i = 0, idx; i < m; i ++ ) {
        char c;
        std::cin >> idx >> c;
        int v = c == '.';
        if (v != a[idx]) {
            if (v) {
                ++ f;
                f += a[idx - 1] && a[idx + 1];
                f -= !a[idx - 1] && !a[idx + 1];
            }
            else {
                -- f;
                f -= a[idx - 1] && a[idx + 1];
                f += !a[idx - 1] && !a[idx + 1];            
            }
            a[idx] = v;
        }
        std::cout << f << '\n';
    }
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}