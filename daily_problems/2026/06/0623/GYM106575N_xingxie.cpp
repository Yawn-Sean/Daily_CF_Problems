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

class segtree 
{
    int n;
    vll mn;
    void up(int p) 
    {
        mn[p] = min(mn[p << 1],mn[p << 1 | 1]);
    }
    void build(int p,int l,int r,vll& a) 
    {
        if (l == r) 
        {
            mn[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    ll query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) return mn[p];
        int m = st + ed >> 1;
        ll res = LLONG_MAX / 2;
        if (l <= m) res = min(res,query(p << 1,st,m,l,r));
        if (r > m) res = min(res,query(p << 1 | 1,m + 1,ed,l,r));
        return res;
    }
public:
    segtree(vll& a) 
    {
        n = a.size();
        mn.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    ll query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }
};
void solve()
{
    int n,ca,cb;
    cin >> n >> ca >> cb;
    vt a(n),b(n);
    for (int i = 0;i < n;i++) cin >> a[i];
    for (int i = 0;i < n;i++) cin >> b[i];
    if (a[0] < b[0]) 
    {
        cout << 0 << endl;
        return;
    }
    ll ans = LLONG_MAX / 2;
    vll pa(n);
    vll pb(n);
    for (int i = 0;i < n;i++) 
    {
        pa[a[i] / 2] = 1LL * i * ca;
        pb[b[i] / 2 - 1] = 1LL * i * cb;
    }
    segtree tr(pb);
    for (int i = 0;i < n;i++) 
    {
        ll res = tr.query(i,n - 1);
        ans = min(ans,pa[i] + res);
    }
    cout << ans << endl;
    // int mn = INT_MAX,mx = 0;
    // for (int i = 0;i < n;i++) 
    // {
    //     mn = min(mn,a[i]);
    //     mx = max(mx,b[i]);
    //     if (mx > mn) 
    //     {
    //         for (int j = 0;j <= i;j++) 
    //         {
    //             if (a[j] < b[i]) 
    //             {
    //                 cout << 1LL * j * ca + 1LL * i * cb << endl;
    //                 return ;
    //             }
    //         }
    //     }
    // }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int _ = 1;
    cin >> _;
    while (_ --) solve();

    return 0;
}