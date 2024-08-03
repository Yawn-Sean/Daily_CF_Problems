#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<pair<int, int>> g[N];
vector<pair<int, int>> rg[N];
vector<pair<int, int>> edge(N);
int a[N];
vector<int> mod = {1000000087, 1000000021, 100000259, 1000000427, 1000001011};
int mo;
void solve() {
    int n, m, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        g[u].push_back({v, i});
        rg[v].push_back({u, i});
        edge[i] = {u, v};
        a[i] = w;
    }
    vector<ll> dis1(n + 1, 1e18);
    vector<ll> cnt1(n + 1, 0);
    dis1[s] = 0;
    cnt1[s] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq1;
    pq1.push({0, s});
    while (!pq1.empty()) {
        auto [d, u] = pq1.top();
        pq1.pop();
        if (d > dis1[u]) continue;
        for (auto [v, i] : g[u]) {
            if (dis1[v] > d + a[i]) {
                dis1[v] = d + a[i];
                cnt1[v] = cnt1[u];
                pq1.push({dis1[v], v});
            } else if (dis1[v] == d + a[i]) {
                cnt1[v] += cnt1[u];
                cnt1[v] %= mo;
            }
        }
    }
    vector<ll> dis2(n + 1, 1e18);
    vector<ll> cnt2(n + 1, 0);
    dis2[t] = 0;
    cnt2[t] = 1;
    priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq2;
    pq2.push({0, t});
    while (!pq2.empty()) {
        auto [d, u] = pq2.top();
        pq2.pop();
        if (d > dis2[u]) continue;
        for (auto [v, i] : rg[u]) {
            if (dis2[v] > d + a[i]) {
                dis2[v] = d + a[i];
                cnt2[v] = cnt2[u];
                pq2.push({dis2[v], v});
            } else if (dis2[v] == d + a[i]) {
                cnt2[v] += cnt2[u];
                cnt2[v] %= mo;
            }
        }
    }
    for (int i = 1; i <= m; i++) {
        int u = edge[i].first, v = edge[i].second;
        if (cnt1[u] * cnt2[v] % mo == cnt1[t] && dis1[t] == dis1[u] + a[i] + dis2[v]) {
            cout << "YES" << endl;
        } else {
            ll tmp = dis1[t] - dis1[u] - dis2[v] - 1;
            if (tmp > 0) {
                cout << "CAN " << a[i] - tmp << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(1, 5);
    mo = mod[dis(gen) - 1];
    while (T--) {
        solve();
    }
    return 0;
}