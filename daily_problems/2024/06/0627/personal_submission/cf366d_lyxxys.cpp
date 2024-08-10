#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1500, inf = 1e9;
struct Edge {
    int to, l, r;
    bool operator <(const Edge &t)const{
        return r-l+1 < t.r-t.l+1;        
    }
};
vector <Edge> g[N];
int n, m;

void solve(){   
    cin >> n >> m;
    vector <int> lto;
    while (m--){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        lto.push_back(c);
        g[a].push_back({b, c, d});
        g[b].push_back({a, c, d});
    }

    function<int()> dijkstra = [&](){
        int res = -inf;
        for (int i = 0; i < lto.size(); ++ i){
            int limit = lto[i];
            priority_queue <pair<int,int>> pq;
            vector <int> dis(n+1, -1);
            dis[1] = inf;
            pq.push({inf, 1});
            while (pq.size()){
                auto top = pq.top();
                pq.pop();
                int u = top.second, rp = top.first;
                if (rp < dis[u]) continue;
                for (auto &it : g[u]){
                    int x = it.to, down = it.l, up = it.r;
                    // 如果大于左端点limit或者权值过大不合法
                    if (down > limit || up < limit) continue;
                    int dist = min(up, rp);
                    if (dist > dis[x]){
                        dis[x] = dist;
                        pq.push({dist, x});
                    }
                }
            }
            res = max(res, dis[n]-limit+1);
        }
        return res;
    };
    for (int i = 1; i <= n; ++ i) dis[i] = -inf;
    int res = dijkstra();
    if (res < 0){
        cout << "Nice work, Dima!\n";
        return;
    } else cout << res << "\n";
}

