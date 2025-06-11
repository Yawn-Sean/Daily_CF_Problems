#pragma GCC optimize("O2")
#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

#define lc (u << 1)
#define rc (u << 1 | 1)
const int M = 5e5 + 5;
const int inf = 1e9;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> nex(n, n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n - 1; i >= 0; i--) {
        if (mp.count(a[i]))
            nex[i] = mp[a[i]];
        mp[a[i]] = i;
    }
    vector<pair<int, int>> v[n];
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--, r--;
        v[l].push_back({r, i});
    }
    vector<int> b(n, inf);
    for (int i = 0; i < n; i++) {
        if (nex[i] != n) {
            b[nex[i]] = nex[i] - i;
        }
    }
    build(b, 1, 1, n);
    vector<int> ans(m);
    for (int l = 0; l < n; l++) {
        for (auto& q : v[l]) {
            int r = q.first, idx = q.second;
            ans[idx] = query(1, l + 1, r + 1);
            if (ans[idx] == inf) ans[idx] = -1;
        }
        if (nex[l] != n)
            update(1, nex[l] + 1, inf);
    }
    for (int i = 0; i < m; i++) cout << ans[i] << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}