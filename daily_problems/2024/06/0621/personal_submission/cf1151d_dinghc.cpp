#include <bits/stdc++.h>

using namespace std;
using li = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    ranges::sort(a, [] (auto& x, auto& y) {
        return x.second - x.first < y.second - y.first;
    });
    li ans = 0LL;
    for (int i = 0; i < n; i++) {
        auto& [f, s] = a[i];
        ans += 1LL * f * i + 1LL * s * (n - i - 1);
    }
    cout << ans << "\n";
    return 0;
}

