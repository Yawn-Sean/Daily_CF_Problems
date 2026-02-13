#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
int a[N];
struct xds{
    struct{
        int sum, l, r, lz;
    }tr[4*N];
    void up(int p){
        tr[p].sum = tr[p << 1].sum + tr[p << 1 | 1].sum;
        return;
    }
    void lazy(int p, int v){
        int num = tr[p].r - tr[p].l + 1;
        tr[p].sum += num * v;
        tr[p].lz += v;
        return;
    }
    void down(int p){
        if(tr[p].lz != 0){
            int v = tr[p].lz;
            lazy(p << 1, v);
            lazy(p << 1 | 1, v);
            tr[p].lz = 0;
        }
        return;
    }
    void build(int p, int l, int r){
        tr[p] = {0, l, r, 0};
        if(l == r){
            tr[p].sum = a[l];
            return ;
        }
        int mid = (l + r)>> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1 , mid + 1, r);
        up(p);
        return ;
    }
    void add(int p, int l, int r, int v){
    	if(l > r)return ;
        if(l <= tr[p].l && tr[p].r <= r){
            lazy(p, v);
            return;
        }
        down(p);
        if(l <= tr[p << 1].r)add(p << 1, l, r, v);
        if(tr[p << 1|1].l <= r)add(p << 1 | 1, l, r, v);
        up(p);
    }
    int query(int p, int l, int r){
    	if(l > r)return 0ll;
        if(l <= tr[p].l && tr[p].r <= r){
            return tr[p].sum;
        }
        down(p);
        int ans = 0;
        if(l <= tr[p << 1].r)ans += query(p << 1, l, r);
        if(tr[p << 1|1].l <= r)ans += query(p << 1|1, l, r);
        return ans;
    }
}k, b;
void solve()
{
    int n;
    cin >> n;
    vector<int> a(n+1), w(n);
    for(int i = 1; i <= n; i ++)cin >> a[i], w[a[i]] = i;
    int l = n, r = 0;
    k.build(1, 1, n);
    b.build(1, 1, n);
    for(int ma = 0; ma < n; ma ++){
        int p = w[ma];
        l = min(l, p);
        r = max(r, p);
        b.add(1, l, r, (n-r+1) * (l));
        k.add(1, 1, l-1, (n-r+1));
        k.add(1, r+1, n, -l);
        b.add(1, r+1, n, (n+1)*l);
    }   
    for(int i = 1; i <= n; i ++)cout << k.query(1, i, i) * i + b.query(1, i, i) << '\n';
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
