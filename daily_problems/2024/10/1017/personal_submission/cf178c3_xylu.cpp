#include <bits/stdc++.h>
using namespace std;

int __FAST_IO__ = []() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    return 0;
}();

void solveC3() {
    int h, m, n;
    cin >> h >> m >> n;
    map<int, int> mp;
    vector<int> group(h, -1), gpos(h, 0), gsize;
    vector<set<pair<int, int>>> empty;
    int g = 0;
    for (int i = 0; i < h; i++) {
        if (group[i] == -1) {
            set<pair<int, int>> s;
            for (int k = 0, v = i; k == 0 || v != i; k++, v = (v + m) % h) {
                group[v] = g;
                gpos[v] = k;
                s.insert({k, v});
            }
            g++;
            empty.push_back(s);
            gsize.push_back(s.size());
        }
    }

    long long ans = 0;
    while (n--) {
        char op; int id, hash;
        cin >> op >> id;
        if (op == '-') {
            int pos = mp[id];
            mp.erase(id);
            empty[group[pos]].insert({gpos[pos], pos});
        } else {
            cin >> hash;
            int gp = group[hash];
            auto it = empty[gp].lower_bound({gpos[hash], hash});
            if (it == empty[gp].end()) {
                auto p = *empty[gp].begin();
                ans += p.first + gsize[gp] - gpos[hash];
                mp[id] = p.second;
                empty[gp].erase(empty[gp].begin());
            } else {
                ans += it->first - gpos[hash];
                mp[id] = it->second;
                empty[gp].erase(it);
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solveC3();
    }

    return 0;
}
