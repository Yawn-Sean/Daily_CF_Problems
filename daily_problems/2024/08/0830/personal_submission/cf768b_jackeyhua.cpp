#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

void solve() {
    ll n, l, r;
    cin >> n >> l >> r;
    if (n <= 1) {
        cout << n << "\n";
        return;
    }
    vector<ll> root, cnt, ss;
    ll t = n;
    while (t) {
        root.push_back(t);
        t >>= 1;
    }
    int size = root.size();
    cnt.resize(size);
    cnt.back() = 1;
    ss.resize(size);
    ss.back() = 1;
    for (int i = cnt.size() - 2; i >= 0; --i) {
        cnt[i] = 2 * cnt[i + 1] + (root[i] % 2);
        ss[i] = 2 * ss[i + 1] + 1;
    }
    ll pref_l = 0, pref_r = 0;
    auto deal = [&](ll pos) -> ll {
        ll cur = 0;
        for (int i = 0; pos && i < size; ++i) {
            ll thres = ss[i] / 2;
            if (pos < thres) {
                continue;
            } else if (pos == thres) {
                cur += cnt[i] / 2;
                break;
            } else {
                cur += cnt[i] / 2 + (root[i] % 2);
                pos -= (thres + 1);
            }
        }
        return cur;
    };
    cout << deal(r) - deal(l - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    solve();
    return 0;
}
