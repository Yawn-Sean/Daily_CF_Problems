#include <bits/stdc++.h>
#define int long long
using namespace std;

static const int INF = 1e18;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;

        vector<int> u(m), v(m), w(m);
        for(int i = 0; i < m; ++i){
            cin >> u[i] >> v[i] >> w[i];
            u[i]--,v[i]--;
        }

        vector<int> order(m);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a, int b){
            return w[a] < w[b];
        });

        vector<int> dis(n, INF);
        dis[0] = 0;

        int pt = 0;
        while(pt < m){
            int npt = pt;
            while(npt < m && w[order[npt]] == w[order[pt]]){
                ++npt;
            }
            vector<pair<int,int>> updates;
            updates.reserve(2 * (npt - pt));

            for(int i = pt; i < npt; ++i){
                int id = order[i];
                int uu = u[id];
                int vv = v[id];

                if(dis[vv] < INF){
                    updates.emplace_back(uu, dis[vv] + 1);
                }
                if(dis[uu] < INF){
                    updates.emplace_back(vv, dis[uu]);
                }
            }

            for(auto &p : updates){
                int node = p.first;
                int d = p.second;
                if(d < dis[node]){
                    dis[node] = d;
                }
            }

            pt = npt;
        }

        int ans = dis[n - 1];
        if(ans >= INF) ans = -1;
        cout << ans << "\n";
    }

    return 0;
}
