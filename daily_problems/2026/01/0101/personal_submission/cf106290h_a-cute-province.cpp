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
    int n;
    cin >> n;
    vector<int> num(n), first_pos(n + 1, -1), last_pos(n + 1, -1), pre_pos(n); 
    for(auto &x : num)cin >> x;
    for(int i = 0; i < n; i ++){
        pre_pos[i] = last_pos[num[i]];
        last_pos[num[i]] = i;
        if(first_pos[num[i]] == -1)first_pos[num[i]] = i;
    }
    int ans = 0;
    for(int i = 1 ; i <= n; i ++){
        if(first_pos[i] != -1)ans++;
    }
    
    tree.build(1, 0, n-1);
    int ma = 0;
    for(int r = 0; r < n; r ++){
        if(last_pos[num[r]] != r)tree.add(1, pre_pos[r]+1, r, 1);
        else{   
            tree.add(1, 0, pre_pos[r] , -1);
            tree.add(1, first_pos[num[r]] + 1, r, 1);
        }
        ma = max(ma, tree.search(1, 0, n-1));
    }
    
    cout << ma + ans << '\n';
}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
