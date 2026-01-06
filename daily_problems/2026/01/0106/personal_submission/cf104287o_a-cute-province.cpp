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
}tree;
void solve() {
    int n, q;
    cin >> n >> q;
    for(int i =1;  i<= n; i ++)cin >> a[i];
    priority_queue<int, vector<int>, greater<int>> pq;
    int sum = a[1];
    tree.build(1, 1, n);
    for(int i = 2; i <= n;i ++){
        if(sum <= a[i])pq.push(i);
        sum += a[i];
    }
    
    while(q--){
        int l, r, x;
        cin >> l >> r >> x;
        tree.add(1, l, r, x);
        if(l > 1 && tree.query(1, 1, l-1) <= tree.query(1, l, l))pq.push(l);
        while(!pq.empty() && tree.query(1, 1, pq.top()-1) > tree.query(1, pq.top(), pq.top())){
            pq.pop();
        }
        if(pq.empty())cout << "-1\n";
        else cout << pq.top() << '\n';
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
