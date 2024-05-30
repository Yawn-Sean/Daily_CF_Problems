#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define eb emplace_back
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)
using pi = pair<int, int>;

inline int red() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = red(), p = red();
    map<pi, int> mp;
    ve<int> a(n);
    rep(i, 0, n) {
        int u = red(), v = red();
        --u, --v;
        if (u > v) {
            swap(u, v);
        }
        a[u]++, a[v]++;
        mp[{u, v}]++;
    }
    int64_t res = 0;
    
    for (auto& [x, y] : mp) {
        int s = a[x.fi] + a[x.se];
        if (s >= p && s - y < p) {
            res--;
        }
    }
    sort(all(a));
    int idx = n - 1;
    rep(i, 0, n) {
        idx = max(idx, i);
        while (i < idx && a[i] + a[idx] >= p) {
            idx--;
        }
        res += n - idx - 1;
    }
    cout << res << '\n';
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
https://codeforces.com/problemset/problem/420/C
*/