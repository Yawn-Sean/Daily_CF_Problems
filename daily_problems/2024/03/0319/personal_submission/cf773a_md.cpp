#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
    ll x, y, p, q;
    cin >> x >> y >> p >> q;

    ll start = -1;
    ll end = 1e9 + 1;

    auto cando = [x, y, p, q](ll m) -> bool {
        return m * p >= x && (q - p) * m >= y - x;
    };

    while (start + 1 < end) {
        auto mid = start + (end - start) / 2;
        if (cando(mid)) {
            end = mid;
        } else {
            start = mid;
        }
    }

    if (cando(start)) {
        cout << start * q - y << endl;
    } else if (cando(end)) {
        cout << end * q - y << endl;
    } else {
        cout << -1 << endl;
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}