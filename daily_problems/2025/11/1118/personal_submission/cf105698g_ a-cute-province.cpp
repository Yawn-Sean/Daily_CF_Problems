#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e9 + 7;
const int N = 5e5 + 10;
int a[N];
struct xds {
	struct node{
		int l, r;
		int sum, lz;
	}tr[N*4];
	void build(int p, int l, int r){
		tr[p] = {l, r, 0, 0};
		if(l == r){
			tr[p].sum = a[l];
			return ;
		}
		int mid = (l + r)>> 1;
		build(2*p, l, mid);
		build(2*p + 1, mid + 1, r);
		tr[p].sum = min(tr[2*p].sum, tr[2*p+1].sum);
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
		tr[p].sum = min(tr[2*p].sum, tr[2*p + 1].sum);
		return ;
	}
	int search(int p, int l, int r){
		if(l > r)return 0ll;
		if(tr[p].l >= l && tr[p].r <= r){
			return tr[p].sum;
		}
		pushdown(p);
		int s = 1e18; 
		if(l <= tr[2*p].r)s = min(s, search(2*p, l, r));
		if(r >= tr[2*p+1].l)s = min(s, search(2*p+1, l, r));
		return s;
	}

}tree;

void solve()
{   
   int  n, q;
   cin >> n >> q;
    tree.build(1, 1, n);
    while(q--){
        int op, l, r;
        cin >> op;
        if(op == 1){
            cin >> l >> r; 
            tree.add(1, l, l,  max(r, a[l]) - a[l]);
            a[l] = max(r, a[l]);
        }
        else{
            cin >> l;
            int x = 0, y = l;
            while(x < y){
                int mid = (x + y)/2+1;
                if(tree.search(1, mid, l) < l)x = mid;
                else y = mid - 1;
            }
            cout << l-x+1 << '\n';
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
    t = 1;
    //cin >> t;    
    while (t--)
    {
        solve();
    }
    return 0;
}
