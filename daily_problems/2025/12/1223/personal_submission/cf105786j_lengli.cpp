#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = (ll)1e18;

inline ll f(ll x, ll l, ll r, ll c) {
    if (l <= x && x <= r) return c;
    if (x < l) return l - x + c;
    return x - r + c;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    vector<ll> outs;
    outs.reserve(t);

    while (t--) {
        int n;
        cin >> n;

        vector<ll> nums(n);
        for (auto &x : nums) cin >> x;

        vector<ll> ls = nums;
        vector<ll> rs = nums;
        vector<ll> cost(n, 0);

        while ((int)ls.size() > 1) {
            vector<ll> nls, nrs, ncost;

            for (int i = 0; i < (int)ls.size(); i += 4) {
                ll l = 0, r = 0, cur = INF;

                for (int j = i; j < i + 4; j++) {
                    ll v = 0;
                    for (int k = i; k < i + 4; k++) {
                        v += f(ls[j], ls[k], rs[k], cost[k]);
                    }

                    if (v < cur) {
                        cur = v;
                        l = r = ls[j];
                    } else if (v == cur) {
                        l = min(l, ls[j]);
                        r = max(r, ls[j]);
                    }

                    v = 0;
                    for (int k = i; k < i + 4; k++) {
                        v += f(rs[j], ls[k], rs[k], cost[k]);
                    }

                    if (v < cur) {
                        cur = v;
                        l = r = rs[j];
                    } else if (v == cur) {
                        l = min(l, rs[j]);
                        r = max(r, rs[j]);
                    }
                }

                nls.push_back(l);
                nrs.push_back(r);
                ncost.push_back(cur);
            }

            ls.swap(nls);
            rs.swap(nrs);
            cost.swap(ncost);
        }

        outs.push_back(f(0, ls[0], rs[0], cost[0]));
    }

    for (ll x : outs) {
        cout << x << '\n';
    }

    return 0;
}
