#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<pair<int,int>> p0, p1;
    for (int i = 0; i < n; i++) {
        int c, v;
        cin >> c >> v;
        if (c == 1) {
            p1.emplace_back(v, i + 1);
        } else {
            p0.emplace_back(v, i + 1);
        }
    }

    for (int i = 0; i < n - 1; i++) {
        auto [v0, idx0] = p0.back(); p0.pop_back();
        auto [v1, idx1] = p1.back(); p1.pop_back();

        if (v0 <= v1 && !p0.empty()) {
            cout << idx0 << ' ' << idx1 << ' ' << v0 << '\n';
            p1.emplace_back(v1 - v0, idx1);
        } else {
            cout << idx0 << ' ' << idx1 << ' ' << v1 << '\n';
            p0.emplace_back(v0 - v1, idx0);
        }
    }

    return 0;
}
