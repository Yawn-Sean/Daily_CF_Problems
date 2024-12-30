#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 998244353;
constexpr int inf = 0x3f3f3f3f;
constexpr ll linf = 0x3f3f3f3f3f3f3f3f;

void solve() {
    int n; cin >> n;
    vector<vector<ll>> d(n + 1, vector<ll>(10, -linf));
    d[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int k; cin >> k;
        vector<ll> card[4];
        while (k--) {
            int u, v; cin >> u >> v;
            card[u].push_back(v);
        }
        ranges::sort(card[1]);
        ll max2 = 0, max3 = 0;
        if (card[2].size() > 0) max2 = ranges::max(card[2]);
        if (card[3].size() > 0) max3 = ranges::max(card[3]);
        for (int m = 0; m < 10; ++m) {
            // 0 card
            d[i][m] = d[i-1][m];
            // 3 cards
            if (card[1].size() >= 3) {
                auto it = card[1].rbegin();
                ll sum = *it;
                if (m <= 2) sum += *it;
                sum += *++it; sum += *++it;
                d[i][m] = max(d[i][m], d[i-1][(m+7)%10] + sum);
            }
            // 2 cards
            if (card[1].size() >= 2 || (card[1].size() > 0 && max2)) {
                auto it = card[1].rbegin();
                ll sum = *it;
                ll v = max2;
                if (m <= 1) sum += max(*it, max2);
                if (card[1].size() >= 2) v = max(v, *++it);
                sum += v;
                d[i][m] = max(d[i][m], d[i-1][(m+8)%10] + sum);
            }
            // 1 card
            ll mx = 0;
            if (card[1].size() > 0) mx = *card[1].rbegin();
            mx = max(mx, max(max2, max3));
            if (!m) mx <<= 1;
            d[i][m] = max(d[i][m], d[i-1][(m+9)%10] + mx);
        }
    }
    println("{}", ranges::max(d[n]));
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
