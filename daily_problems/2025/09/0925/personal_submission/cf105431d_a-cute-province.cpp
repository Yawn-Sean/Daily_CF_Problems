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
int f[N];
struct xds {
	struct node{
		int l, r;
		int sum, lz;
	}tr[N*4];
	void build(int p, int l, int r){
		tr[p] = {l, r, 0, 0};
		if(l == r){
			tr[p].sum = f[l];
			return ;
		}
		int mid = (l + r)>> 1;
		build(2*p, l, mid);
		build(2*p + 1, mid + 1, r);
		tr[p].sum = max(tr[2*p].sum, tr[2*p+1].sum);
		return ;
	}
	void pushdown(int p){
		if(tr[p].lz != 0){
			int k = tr[p].lz;
			tr[2*p].lz += k;
			tr[2*p+1].lz += k;
			tr[2*p].sum += k;
			tr[2*p + 1].sum += k;
			tr[p].lz = 0;
		}
		return ;
	}
	void add(int p, int l, int r, int k){
		if(l > r)return;
		if(tr[p].l >= l && r >= tr[p].r){
			tr[p].sum += k;
			tr[p].lz += k;
			return ;
		}
		pushdown(p);
		if(l <= tr[p*2].r)add(2*p, l, r, k);
		if(r >= tr[p*2+1].l)add(2*p+1, l, r, k);
		tr[p].sum = max(tr[2*p].sum, tr[2*p + 1].sum);
		return ;
	}
	int search(int p, int l, int r){
		if(l > r)return 0ll;
		if(tr[p].l >= l && tr[p].r <= r){
			return tr[p].sum;
		}
		pushdown(p);
		int s = -1e18;
		if(l <= tr[2*p].r)s = max(s, search(2*p, l, r));
		if(r >= tr[2*p+1].l)s = max(s, search(2*p+1, l, r));
		return s;
	}

}tree;
void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(k*n+1), b(k*n+1);
    vector<vector<int>> pos(k*n+1);
    for(int i =1 ; i<=n*k; i ++)cin >> a[i];
    for(int i = 1; i <= n*k; i ++)cin >> b[i];
    tree.build(1, 1, n*k);
	for (int i = n*k; i >= 1; i --)pos[b[i]].emplace_back(i);
    for(int i = 1; i <= n*k; i++){
        for(auto u : pos[a[i]]){
            int p1 = tree.search(1, 1, u-1), p2 = tree.search(1, u, u);
            tree.add(1, u, u, p1+1-p2);
        }
       
    }
    cout << tree.search(1, 1, n*k) << '\n';
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
