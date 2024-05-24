#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

void solve() {
    int n, p; cin >> n >> p;
    unordered_map<ll, int> mp;
    vector<int> cnt0(n);
    for (int i = 0; i < n; ++i) {
        int x, y; cin >> x >> y;
        if (x > y) swap(x, y);
        ll t = 1ll * MOD * x + y;
        mp[t] += 1;
        cnt0[x - 1] += 1;
        cnt0[y - 1] += 1;
    }

    vector<int> cnt(cnt0.begin(), cnt0.end());
    sort(cnt.begin(), cnt.end());
    int l = 0, r = n - 1;
    ll ans = 0;
    while (l < r) {
        if (cnt[l] + cnt[r] < p) l += 1;
        else {
            ans += r - l;
            r -= 1;
        }
    }

    for (auto &[key, val]: mp) {
        int x = key / MOD;
        int y = key % MOD;
        int sm = cnt0[x - 1] + cnt0[y - 1];
        if (sm >= p && sm - val < p) ans -= 1;
    }

    cout << ans << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}
