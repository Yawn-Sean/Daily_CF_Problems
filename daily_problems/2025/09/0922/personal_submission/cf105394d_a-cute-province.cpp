#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10;
const int mod = 1e9 + 7;
int a[N];
struct xds{
    struct{
        long long sum, l, r, lz;
    } tr[4*N];

    long long norm(long long val) {
        return (val % mod + mod) % mod;
    }

    void up(int p){
        tr[p].sum = norm(tr[p << 1].sum + tr[p << 1 | 1].sum);
    }

    void lazy(int p, int v){
        if (v == 0) return;
        long long num = tr[p].r - tr[p].l + 1;
        tr[p].sum = norm(tr[p].sum + num * v);
        tr[p].lz = norm(tr[p].lz + v);
    }

    void down(int p){
        if(tr[p].lz != 0){
            long long v = tr[p].lz;
            lazy(p << 1, v);
            lazy(p << 1 | 1, v);
            tr[p].lz = 0;
        }
    }

    void build(int p, int l, int r){
        tr[p] = {0, (long long)l, (long long)r, 0};
        if(l == r) return;
        int mid = (l + r) >> 1;
        build(p << 1, l, mid);
        build(p << 1 | 1 , mid + 1, r);
    }

    void add(int p, int l, int r, int v){
        if (l > r) return;
        if(l <= tr[p].l && tr[p].r <= r){
            lazy(p, v);
            return;
        }
        down(p);
        long long mid = (tr[p].l + tr[p].r) >> 1;
        if(l <= mid) add(p << 1, l, r, v);
        if(r > mid) add(p << 1 | 1, l, r, v);
        up(p);
    }

    long long query(int p, int l, int r){
        if (l > r) return 0ll;
        if(l <= tr[p].l && tr[p].r <= r){
            return tr[p].sum;
        }
        down(p);
        long long ans = 0;
        long long mid = (tr[p].l + tr[p].r) >> 1;
        if(l <= mid) ans = norm(ans + query(p << 1, l, r));
        if(r > mid) ans = norm(ans + query(p << 1 | 1, l, r));
        return ans;
    }
}tree1, tree2;
int qpow(int a, int b){
    int res = 1;
    while(b){
        if(b&1)res = res * a%mod;
        b >>= 1;
        a = a * a %mod;
    }
    return res;
}
int inv(int x){
    return qpow(x, mod-2);
}
void solve()
{
    int n, q;
    long double pr;
    cin >> n >> q >> pr;
    pr = (1-pr) * 1000000;
    int p = pr + 0.5;
    p = (p * qpow(1000000, mod-2))%mod;
    tree1.build(1, 1, n);
    tree2.build(1, 1, n);
    while(q--){
         char op;
         cin >> op;
         int b, x;
         if(op == '+'){
            cin >> b >> x;
            tree1.add(1, 1, x, b * qpow(p, x)%mod);
             tree2.add(1, x+1, n, b * inv(qpow(p, x))%mod);
         }
         else if(op == '-'){
            cin >> b >> x;
             tree1.add(1, 1, x, (mod-b * qpow(p, x)%mod));
             tree2.add(1, x+1, n, (mod-b * inv(qpow(p, x)%mod)));
         }
         else{
            cin >> x;
            cout << (tree1.query(1, x, x) * inv(qpow(p, x))%mod + tree2.query(1, x, x) * qpow(p, x) %mod)%mod << '\n';
         }
    }
 
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
