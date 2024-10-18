#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> us(m), vs(m), ws(m);
    vector<vector<int>> path(n);

    for (int i = 0; i < m; i ++) {
        cin >> us[i] >> vs[i] >> ws[i];
        us[i] --, vs[i] --;
        path[us[i]].emplace_back(i);
        path[vs[i]].emplace_back(i);
    }

    vector<long long> dis(n, 1e15);
    dis[0] = 0;

    vector<int> parent(n, -1);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});

    while (pq.size()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (dis[u] == d) {
            for (auto &i: path[u]) {
                int v = us[i] ^ vs[i] ^ u;
                if (dis[v] > dis[u] + ws[i]) {
                    dis[v] = dis[u] + ws[i];
                    parent[v] = i;
                    pq.push({dis[v], v});
                }
            }
        }
    }

    vector<int> st_range(n - 1);
    iota(st_range.begin(), st_range.end(), 1);
    sort(st_range.begin(), st_range.end(), [&] (int i, int j) {return dis[i] < dis[j];});

    int ans = min(k, n - 1);
    cout << ans << '\n';
    for (int i = 0; i < ans; i ++)
        cout << parent[st_range[i]] + 1 << ' ';

    return 0;
}