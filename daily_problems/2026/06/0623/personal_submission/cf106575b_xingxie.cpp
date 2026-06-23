#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
using i128 = __int128_t;
using vt = vector<int>;
using vd = vector<double>;
using vll = vector<long long>;
using vvt = vector<vector<int>>;
using vvd = vector<vector<double>>;
using vvll = vector<vector<long long>>;
using vvvt = vector<vector<vector<int>>>;
using vvvll = vector<vector<vector<long long>>>;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using pdd = pair<double,double>;
using vpii = vector<pair<int,int>>;
using vpll = vector<pair<ll,ll>>;
using vpdd = vector<pair<double,double>>;
using vvpii = vector<vector<pair<int,int>>>;
using vvpll = vector<vector<pair<ll,ll>>>;
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
    // cout << fixed << setprecision(10);
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m,k;
    ll c;
    cin >> n >> m >> k >> c;
    vt p(n);
    for (int i = 0;i < k;i++) 
    {
        int x;
        cin >> x;
        x--;
        p[x] = 1;
    }
    vt a(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    vvpii g(n);
    for (int i = 0;i < m;i++) 
    {
        int u,v,w = 0;
        cin >> u >> v;
        u--;v --;
        g[u].push_back({v,w});
        g[v].push_back({u,w});
    }
    pqueue<pll,vpll,greater<>> pq;
    vll dis(n,LLONG_MAX / 2);
    dis[0] = 0;
    pq.push({0,0});
    while (!pq.empty()) 
    {
        auto [d,x] = pq.top();
        pq.pop();
        if (d > dis[x]) continue;
        if (x == n - 1) 
        {
            if (d > c) cout << -1 << endl;
            else cout << d << endl;
            return ;
        }
        for (auto& [y,w] : g[x]) 
        {
            if (p[y]) 
            {
                for (auto& [z,w2] : g[y]) 
                {
                    if (z == x) continue;
                    if (p[z]) continue;
                    ll nd = a[y] + d;
                    if (nd < dis[z]) 
                    {
                        dis[z] = nd;
                        pq.push({nd,z});
                    }
                }
            }
            else 
            {
                ll nd = d + w;
                if (nd < dis[y]) 
                {
                    dis[y] = nd;
                    pq.push({nd,y});
                }
            }
        }
    }
    cout << -1 << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    // cin >> _;
    while (_ --) solve();

    return 0;
}
