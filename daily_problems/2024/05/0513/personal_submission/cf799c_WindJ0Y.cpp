#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, c, d; cin >> n >> c >> d;
    vector<pair<int, int>> cs, ds;
    
    while (n --) {
        int v, cost; cin >> v >> cost;
        string tp; cin >> tp;
        if (tp == "C") {
            cs.emplace_back(cost, v);
        } else {
            ds.emplace_back(cost, v);
        }
    }

    sort(cs.begin(), cs.end());
    sort(ds.begin(), ds.end());

    int ans = 0;

    {
        int va = -1e9;
        int vb = -1e9;
        for (auto [cost, v] : cs) {
            if (cost <= c) {
                va = max(va, v);
            }
        }
        for (auto [cost, v] : ds) {
            if (cost <= d) {
                vb = max(vb, v);
            }
        }
        ans = max(ans, va + vb);
    }

    auto ues_one = [&] (const vector<pair<int, int>> &s, int mxv) {
        multiset<pair<int, int>> canuse;
        int fpos = 0;

        for (int p = s.size() - 1; p >= 0; p --) {
            auto [cost, v] = s[p];
            while (fpos < s.size() && s[fpos].first + cost <= mxv) {
                canuse.emplace(s[fpos].second, s[fpos].first);
                fpos ++;
            }
            if (canuse.size()) {
                auto [bv, bcost] = *canuse.rbegin();
                if (v == bv && cost == bcost && fpos > p) {
                    if (canuse.size() < 2) continue;
                    auto [nbv, nbcost] = *next(canuse.rbegin());
                    bv = nbv; bcost = nbcost;
                }
                ans = max(ans, v + bv);
            }
        }
    };

    ues_one(cs, c);
    ues_one(ds, d);
    
    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    // cin >> T;

    while (T--) {
        work();
    }
}