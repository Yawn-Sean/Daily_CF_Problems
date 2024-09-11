#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    string a, b, c;
    cin >> a >> b >> c;
    
    auto cal = [](const string &s, array<int, 26> &arr) { for (auto c: s) ++arr[c - 'a']; };

    array<int, 26> na = {0}, nb = {0}, nc = {0};
    cal(a, na); cal(b, nb); cal(c, nc);
    int mb = ranges::min(views::zip_transform([](auto a, auto b){ return b == 0 ? inf : a / b; }, na, nb));
    int ab = 0, ac = 0;
    for (int db = 0; db <= mb; ++db) {
        int dc = ranges::min(views::zip_transform([&](auto a, auto b, auto c){ return c == 0 ? inf : (a - db * b) / c; }, na, nb, nc));
        if (ab + ac < db + dc) ab = db, ac = dc;
    }
    string ans;
    for (int i = 0; i < ab; ++i) ans += b;
    for (int i = 0; i < ac; ++i) ans += c;
    for (int i = 0; i < 26; ++i) ans += string(na[i] - ab * nb[i] - ac * nc[i], i + 'a');
    println("{}", ans);
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
