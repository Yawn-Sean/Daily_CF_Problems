#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
struct xds {
	struct node{
		int l, r;
		int sum, lz;
	}tr[N*4];
	void build(int p, int l, int r){
		tr[p] = {l, r, 0, 0};
		if(l == r){
			tr[p].sum = 0;
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
    int M = 1e6;
    int q;
    cin >> q;
    tree.build(1, 0, M);
    for(int i = 0; i <= M;i ++)tree.add(1, i, i, -(i+1));
    while(q--){
        int op;
        cin >> op;
        int x;
        if(op == 1){
            cin >> x;
            tree.add(1, x, M, 1);
        }
        else{
            cin >> x;
            tree.add(1, x, M, -1);
        }
        if(tree.search(1, 0, M) < 0){
            cout << 0 << '\n';
            continue;
        }
        int l = 0, r = M;
        while(l < r){
            int mid = (l + r)/2+1;
            if(tree.search(1, mid, M) >= 0)l = mid;
            else r = mid-1;
        }
        cout << l+1 << '\n';
    }
}
int cute_prov0nce()
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
