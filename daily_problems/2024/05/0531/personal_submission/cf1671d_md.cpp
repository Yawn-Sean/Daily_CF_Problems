// 0531
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, x;
    std::cin >> n >> x;
    vector<int> a(n);
    copy_n(istream_iterator<int>(cin), n, begin(a));

    i64 ret = 0;
    for (int i = 1; i < n; ++i) {
        ret += abs(a[i] - a[i - 1]);
    }

    int v1 = min({ a[0] - 1, a.back() - 1, 2 * (std::ranges::min(a) - 1) });
    int vx = min({ x - a[0], x - a.back(), 2 * (x - std::ranges::max(a)) });

    ret += max(v1, 0) + max(vx, 0);
    cout << ret << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}