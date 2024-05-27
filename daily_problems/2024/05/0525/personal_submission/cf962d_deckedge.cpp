#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define all(x) (x).begin() + 1, (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int64_t>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red();
    vector<int> a(n);
    set<pi> b;
    map<int64_t, set<int>> mp;
    rep(i, 0, n) {
        a[i] = red();
        mp[a[i]].insert(i);
    }
    while (mp.size()) {
        auto it = *mp.begin();
        mp.erase(mp.begin());
        while (it.se.size() >= 2) {
            it.se.erase(it.se.begin());
            mp[it.fi * 2].insert(*it.se.begin());
            it.se.erase(it.se.begin());
        }
        if (it.se.size()) {
            b.insert({*it.se.begin(), it.fi});
        }
    }
    cout << b.size() << '\n';
    for (auto& it : b) {
        cout << it.se << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);


    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}

/*
https://codeforces.com/problemset/problem/962/D
*/
