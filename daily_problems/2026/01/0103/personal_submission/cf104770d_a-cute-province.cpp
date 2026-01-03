#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;
    map<PII, int> e;
    vector<int> deg(n+1);
    for(int i = 1; i <= m + k; i ++){
        int u, v;
        cin >> u >> v;
        if(u > v)swap(u, v);
        deg[u] ^= 1, deg[v] ^= 1;
        e[{u, v}]++;
    }
    vector<array<int,3>> opt;
    for(int i =1 ; i <= n; i ++){
        if(deg[i]){
            cout << "NO\n";
            return ;
        }
    }
    for(auto [E, c] : e){
        if(c > 1)continue;
        if(E.x != 1 && E.y != 1)
        opt.push_back({1, E.x, E.y});
        
    }
    cout << "YES\n";
    cout << opt.size() << '\n';
    for(auto v : opt)cout << v[0] <<' ' << v[1] <<' ' << v[2] << '\n';
   
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
