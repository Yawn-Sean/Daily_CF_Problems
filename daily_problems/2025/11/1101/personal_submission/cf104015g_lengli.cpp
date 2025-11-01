#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 200000;   
    int n;
    if (!(cin >> n)) return 0;

    vector<ll> cnt1(M + 5, 0), cnt2(M + 5, 0);
    vector<int> xs; xs.reserve(n);
    vector<int> ys; ys.reserve(n);

    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        cnt1[x] += 1;
        cnt2[y] += 1;
        xs.push_back(x);
        ys.push_back(y);
    }

    auto comb2 = [](ll v) -> ll {
        if (v < 2) return 0;
        return v * (v - 1) / 2;
    };
    auto comb3 = [](ll v) -> ll {
        if (v < 3) return 0;
        return v * (v - 1) * (v - 2) / 6;
    };

    ll total = 0;

    ll dp0 = 1, dp1 = 0, dp2 = 0, dp3 = 0;
    for (ll x : cnt1) {
        dp3 += dp2 * x;
        dp2 += dp1 * x;
        dp1 += dp0 * x;
    }
    total += dp3;

    dp0 = 1; dp1 = 0; dp2 = 0; dp3 = 0;
    for (ll x : cnt2) {
        dp3 += dp2 * x;
        dp2 += dp1 * x;
        dp1 += dp0 * x;
    }
    total += dp3;

    ll dup = comb3(n);

    for (ll v : cnt1) {
        dup -= comb2(v) * (n - v);
    }
    for (ll v : cnt2) {
        dup -= comb2(v) * (n - v);
    }

    for (int i = 0; i < n; ++i) {
        dup += (cnt1[xs[i]] - 1) * (cnt2[ys[i]] - 1);
    }

    for (ll v : cnt1) dup -= comb3(v);
    for (ll v : cnt2) dup -= comb3(v);

    cout << (total - dup) << '\n';
    return 0;
}
