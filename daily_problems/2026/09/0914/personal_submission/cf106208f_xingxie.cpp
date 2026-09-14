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
using tri = tuple<int,int,int>;
using trl = tuple<ll,ll,ll>;
using vtri = vector<tuple<int,int,int>>;
using vtrl = vector<tuple<ll,ll,ll>>;
#define YES cout << "YES" << endl
#define Yes cout << "Yes" << endl
#define NO cout << "NO" << endl
#define No cout << "No" << endl
#define fi first
#define se second
#define umap unordered_map
#define uset unordered_set
#define pqueue priority_queue
#define mset multiset
#define endl '\n'
//const int MOD = 998244353;
//const int MOD = (int)1e9+7;

void solve()
{
    int n,m;
    cin >> n >> m;
    vvll dis(n,vll(n,LLONG_MAX / 2));
    for (int i = 0;i < m;i++)
    {
        ll u,v,w;
        cin >> u >> v >> w;
        u--;v--;
        dis[u][v] = min(dis[u][v],w);
        dis[v][u] = min(dis[v][u],w);
    }
    for (int i = 0;i < n;i++) dis[i][i] = 0;
    for (int k = 0;k < n;k++)
    {
        for (int i = 0;i < n;i++)
        {
            for (int j = 0;j < n;j++)
            {
                dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]);
            }
        }
    }
    int N = n;
    cin >> n >> m;
    vvll a(n,vll(3)),b(m,vll(3));
    for (int i = 0;i < n;i++) 
    {
        for (int j = 0;j < 3;j++) cin >> a[i][j];
        a[i][2]--;
    } 
    for (int i = 0;i < m;i++) 
    {
        for (int j = 0;j < 3;j++) cin >> b[i][j];
        b[i][2]--;
    } 
    ranges::sort(a);
    ranges::sort(b);
    int i = 1,j = 1;
    ll ans = 0;
    while (i < n && j < m)
    {
        int pa = a[i - 1][2],pb = b[j - 1][2];
        int na = a[i][2],nb = b[j][2];
        ll la = a[i - 1][1],ra = a[i][0];
        ll lb = b[j - 1][1],rb = b[j][0];
        ll mx = 0;
        for (int p = 0;p < N;p++)
        {
            if (dis[pa][p] + dis[p][na] >= ra - la) continue;
            if (dis[pb][p] + dis[p][nb] >= rb - lb) continue;
            ll ar = max(la + dis[pa][p],lb + dis[pb][p]);
            ll le = min(ra - dis[p][na],rb - dis[p][nb]);
            mx = max(mx,le - ar);
        }
        ans += mx;
        if (ra < rb) i++;
        else if (ra > rb) j++;
        else i++,j++;
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << fixed << setprecision(15);
    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}