#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n; cin >> n;
    string s, t; cin >> s >> t;

    int l = 0, r = n - 1;
    while (l < n && s[l] == t[l]) l += 1;
    while (r >= 0 && s[r] == t[r]) r -= 1;

    function<int(int, int)> f = [&](int l, int r) {
        if (l == r) return 2;
        int len = r - l;
        int ans = 0;
        if (memcmp(s.c_str() + l, t.c_str() + l + 1, len) == 0) ans += 1;
        if (memcmp(s.c_str() + l + 1, t.c_str() + l, len) == 0) ans += 1;
        return ans;
    };

    cout << f(l, r) << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
