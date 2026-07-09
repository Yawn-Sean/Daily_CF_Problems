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
    vt sum;
    vt isu,upd;
    void up(int p) 
    {
        sum[p] = sum[p << 1] + sum[p << 1 | 1];
    }
    void down(int p,int ll,int lr) 
    {
        if (isu[p]) 
        {
            sum[p << 1] = ll * upd[p];
            sum[p << 1 | 1] = lr * upd[p];
            isu[p << 1] = 1;
            isu[p << 1 | 1] = 1;
            upd[p << 1] = upd[p];
            upd[p << 1 | 1] = upd[p];
            isu[p] = 0;
        }
    }
    void build(int p,int l,int r,vt& a) 
    {
        if (l == r) 
        {
            sum[p] = a[l];
            return ;
        }
        int m = l + r >> 1;
        build(p << 1,l,m,a);
        build(p << 1 | 1,m + 1,r,a);
        up(p);
    }
    void update(int p,int st,int ed,int l,int r,int v) 
    {
        if (l <= st && r >=ed) 
        {
            int len = ed - st + 1;
            sum[p] = v * len;
            isu[p] = 1;
            upd[p] = v;
            return ;
        }
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) update(p << 1,st,m,l,r,v);
        if (r > m) update(p << 1 | 1,m + 1,ed,l,r,v);
        up(p);
    }
    int query(int p,int st,int ed,int l,int r) 
    {
        if (l <= st && r >= ed) 
        {
            return sum[p];
        }
        int res = 0;
        int m = st + ed >> 1;
        down(p,m - st + 1,ed - m);
        if (l <= m) res += query(p << 1,st,m,l,r);
        if (r > m) res += query(p << 1 | 1,m + 1,ed,l,r);
        return res;
    }
public:
    segtree(vt& a) 
    {
        n = a.size();
        sum.assign(n << 2,0);
        isu.assign(n << 2,0);
        upd.assign(n << 2,0);
        build(1,0,n - 1,a);
    }
    void update(int l,int r,int v) 
    {
        update(1,0,n - 1,l,r,v);
    }
    int query(int l,int r) 
    {
        return query(1,0,n - 1,l,r);
    }

};
void solve()
{
    int n,m;
    cin >> n >> m;
    vvt a(m);
    for (int i = 0;i < m;i++) 
    {
        int x1,x2,y;
        cin >> x1 >> x2 >> y;
        x1--,x2--;
        a[i] = {x1,x2,y};
    }
    ranges::sort(a,{},[&](auto& b) {return b[2];});
    vt tmp(n,1);
    segtree tr(tmp);
    for (auto& g : a) 
    {
        int x1 = g[0],x2 = g[1],y = g[2];
        if (tr.query(x1,x2)) 
        {
            tr.update(x1,x2,0);
            tr.update(x1,x1,1);
            tr.update(x2,x2,1);
        }
        // cout << x1 << " " << x2 << endl;
    }
    cout << tr.query(0,n - 1) << endl;
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