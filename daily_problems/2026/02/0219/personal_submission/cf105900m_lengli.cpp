#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll INF = 1e12;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll n, m;
    cin >> n >> m;

    vector<vector<ll>> path(n);

    auto encode = [&](ll d, ll u) {
        return d * n + u;
    };

    for (int i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        u--; 
        v--;
        path[u].push_back(encode(w, v));
    }

    vector<ll> dis(n, INF);
    dis[0] = 0;

    priority_queue<ll, vector<ll>, greater<ll>> pq;
    pq.push(encode(0, 0));

    vector<ll> order;

    while (!pq.empty()) {
        ll top = pq.top();
        pq.pop();

        ll d = top / n;
        ll u = top % n;

        if (dis[u] == d) {
            order.push_back(u);
            for (ll msk : path[u]) {
                ll w = msk / n;
                ll v = msk % n;

                if (dis[v] > dis[u] + w) {
                    dis[v] = dis[u] + w;
                    pq.push(encode(dis[v], v));
                }
            }
        }
    }

    vector<ll> ans(n, INF);
    ans[0] = 0;

    for (ll u : order) {
        for (ll msk : path[u]) {
            ll w = msk / n;
            ll v = msk % n;

            if (dis[v] == dis[u] + w) {
                ans[v] = min(ans[v], max(ans[u], w));
            }
        }
    }

    cout << dis[n - 1] << " " << ans[n - 1] << "\n";

    return 0;
}
