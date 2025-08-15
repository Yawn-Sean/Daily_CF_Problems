#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10    ; 
const int mod = 1e9 + 7;
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
        if(l <= tr[p].l && tr[p].r <= r){
            return tr[p].sum;
        }
        down(p);
        int ans = 0;
        if(l <= tr[p << 1].r)ans += query(p << 1, l, r);
        if(tr[p << 1|1].l <= r)ans += query(p << 1|1, l, r);
        return ans;
    }
}tree;
void solve()
{
    int n;
    cin >> n;
    int r = 1;
    tree.build(1, 1, n+1);
    while(n--){
        int op, y, x;
        cin >> op;
        if(op == 1){
            cin >> x >>y;
            tree.add(1, 1, x, y);
        }
        else if(op == 2){
            cin >> x;
            tree.add(1, r+1, r+1, x);
            r++;
        }
        else{
            tree.add(1, r, r, -tree.query(1, r, r));
            r--;
        }
        cout << fixed<< setprecision(6)<<(double)tree.query(1, 1, r)/r << '\n';
    }
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);      
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
