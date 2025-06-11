#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 1050, M = 1<<10, mod = 998244353, inf = 1e9;
struct Edges{
    int u, v, len;
    bool operator <(Edges &t){
        return len < t.len;
    }
};
void solve(){
    int n, m, k;
    cin >> n >> m >> k;
    vector <Edges> edges;
    for (int i = 0; i < m; ++ i){
        int a, b, c;
        cin >> a >> b >> c;
        -- a, -- b;
        edges.push_back({a, b, c});
    }
    vector <int> p(n);
    iota(p.begin(), p.end(), 0); 

    function<int(int)> find = [&](int x)->int{
        return p[x]==x ? x : p[x] = find(p[x]);
    };

    sort(edges.begin(), edges.end());
    int Max = 0;
    ll res = 0;
    for (int i = 0; i < m; ++ i){
        auto &it = edges[i];
        int pa = find(it.u), pb = find(it.v);
        if (pa != pb){
            if (it.len > k) res += abs(it.len-k);
            Max = max(Max, it.len);
            p[pb] = pa;
        }
    }
    if (Max < k){
        res = 1e18;
        for (auto &it : edges){
            res = min(res, 1ll*abs(it.len-k));
        }
    }
    cout << res << "\n";
}
