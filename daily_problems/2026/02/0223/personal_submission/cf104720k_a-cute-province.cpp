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
const int N = 2e5 + 10;
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
			tr[p].sum = k;
	
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
    int n;
    cin >> n;
    vector<int> arr;
    vector<PII> ve;
    for(int i = 1; i <= n; i ++){
        int r, R;
        cin >> r >> R;
        ve.emplace_back(r, R);
        arr.emplace_back(r);
        arr.emplace_back(R);
    }
    map<int, int> id, nid;
    // std::vector<int> arr;
    std::vector<int> tmp(arr);  
    std::sort(tmp.begin(), tmp.end());
    tmp.erase(std::unique(tmp.begin(), tmp.end()), tmp.end());
    for (int i = 0; i < 2*n; ++i){
        int p = std::lower_bound(tmp.begin(), tmp.end(), arr[i]) - tmp.begin();
        id[arr[i]] = p;
        nid[p] = arr[i];
    }
    
    sort(ve.begin(), ve.end(), [&](auto i, auto j){
        return i.y < j.y;
    });
    tree.build(1, 1, 2*n);
    int ans = -1e18;
    for(auto [r, R] : ve){
        
        int val = tree.search(1, 1, id[r]) + 2*(R*R-r*r);
        int old = tree.search(1, 1, id[R]);
        int ne = max(val, old);
        //cout << r <<' ' << R <<' ' << ne - R*R<< '\n';
        tree.add(1, id[R], id[R], ne);
        ans = max(ans, ne-R*R);
    }
    cout << ans << '\n';
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
