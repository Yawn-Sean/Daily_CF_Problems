#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;
const int inf = 1e8 + 7, P = 1e9 + 7;

/*
    是否存在必胜？
    -> 可以跳到必败的位置
*/


void solve() {
    int n;
    std::cin >> n;
    std::vector<int> a(n), pos(n);
    std::vector<bool> f(n);
    std::string res(n, 'B');
    for (int i = 0; i < n; i ++ ) std::cin >> a[i], pos[a[i] - 1] = i;
    for (int i = n; i; i -- ) {
        int j = pos[i - 1];
        while (j >= i) j -= i;
        for (; j < n; j += i) {
            if (a[j] <= i) continue;
            if (!f[j]) {
                f[pos[i - 1]] = true;
                break;
            }
        }
        if (f[pos[i - 1]]) res[pos[i - 1]] = 'A';
    }
    std::cout << res;
}

int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}