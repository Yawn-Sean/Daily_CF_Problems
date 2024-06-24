#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll A, B, q;
    cin >> A >> B >> q;

    auto get = [&](ll i) {
        return A + (i - 1) * B;
    };
    auto judge = [&](ll l, ll r, ll t, ll m) {
        return get(r) <= t && (get(l) + get(r)) * (r - l + 1) / 2 <= m * t;
    };

    while (q--) {
        ll l, t, m;
        cin >> l >> t >> m;

        if (get(l) > t) {
            cout << "-1\n";
        } else {
            int bot = 0, top = 1e6;
            while (bot < top) {
                int mid = (bot + top + 1) / 2;
                if (judge(l, l + mid, t, m)) {
                    bot = mid;
                } else {
                    top = mid - 1;
                }
            }

            cout << bot + l << "\n";
        }
    }

    return 0;
}