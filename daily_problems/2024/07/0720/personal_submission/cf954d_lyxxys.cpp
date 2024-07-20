#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1050, mod = 1070777777, inf = 1e9;
/*

*/
vector <int> g[N];
int Go[N][N];
void solve(){
    int n, m, S, T;
    cin >> n >> m >> S >> T;

    while (m--){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
        Go[a][b] = 1, Go[b][a] = 1;
    }

    auto dijkstra = [&](int S)->vector<int>{
        priority_queue<Pii, vector<Pii>, greater<Pii>> pq;
        vector<int> dist(n+1, inf);
        pq.push({0, S});
        dist[S] = 0;
        while (!pq.empty()){
            auto [odis, t] = pq.top();
            pq.pop();
            if (odis > dist[t]) continue;
            for (auto x : g[t]){
                if (dist[x] > odis+1){
                    dist[x] = odis+1;
                    pq.push({dist[x], x});
                }
            }
        }
        return dist;
    };

    vector <int> distN = dijkstra(S);
    vector <int> distT = dijkstra(T);

    int res = 0, diso = distN[T];
    for (int i = 1; i <= n; ++ i){
        for (int j = i+1; j <= n; ++ j){
            if (Go[i][j]) continue;
            int dis = min(distN[i]+distT[j], distN[j]+distT[i]) + 1;
            if (dis >= diso){
                ++ res;
            }
        }
    }
    cout << res << "\n";
}
