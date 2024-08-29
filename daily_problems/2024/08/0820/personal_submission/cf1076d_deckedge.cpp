#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define rep(i, a, b) for (int i = a; i < b; i++)
using i64 = long long;
using pl = pair<i64, pair<int, int>>;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read(), m = read(), k = read();
    ve<ve<pl>> g(n + 1);
    ve<i64> dis(n + 1, 1e15);
    ve<int> res;
    rep(i, 1, m + 1) {
        int l = read(), r = read(), w = read();
        g[l].push_back({w, {i, r}});
        g[r].push_back({w, {i, l}});
    }
    priority_queue<pl, ve<pl>, greater<pl>> q;
    dis[1] = 0;
    q.push({0, {0, 1}});
    while(q.size() && int(res.size()) <= k) {
        auto [d, v] = q.top();
        q.pop();
        if (dis[v.se] != d) {
            continue;
        }
        res.emplace_back(v.fi);
        for (auto [t, u] : g[v.se]) {
            int j = u.se;
            if (dis[j] > dis[v.se] + t) {
                dis[j] = dis[v.se] + t;
                q.push({dis[j], {u.fi, j}});
            }
        }
    }
    int len = res.size();
    cout << len - 1 << '\n';
    rep(i, 1, len) {
        cout << res[i] << " \n"[i == len - 1];
    }

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while(t--) {
        solve(); 
    }
}