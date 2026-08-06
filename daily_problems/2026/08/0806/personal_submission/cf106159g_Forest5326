/*凡修道半年，幸得天诛，道消还天。*/ 
#include <bits/stdc++.h>
using namespace std;
#define Master signed 
#define Forest_5326 main 
// #define int long long
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for (int i=r;i>=l;--i)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define endl '\n' 
#define no cout << "NO" << endl
#define yes cout << "YES" << endl
#define alice cout << "Alice" << endl
#define bob cout << "Bob" << endl
#define dbg(x) cout << #x << " = " << x << endl
#define dbgv(v) cout << #v << ": "; for(auto x:v) cout << x << ' '; cout << endl
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> PII;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
using vvll = vector<vll>;
const ll inf = 0x3f3f3f3f3f3f3f3fLL;
const int infi = 0x3f3f3f3f;
const int MOD = 998244353; 
const int mod = 1e9 + 7; 
const int N = 1e6 + 10;
int dx[] = {0,1,0,-1,1,1,-1,-1};
int dy[] = {1,0,-1,0,1,-1,-1,1};
int gcd(int a,int b){return b == 0 ? a : gcd(b,a % b);}
long long gcd(long long a, long long b) {return b == 0 ? a : gcd(b, a % b);}
long long lcm(long long a, long long b) {return (a / gcd(a, b)) * b;}
ll ksm(ll a, ll b, ll p) {ll res = 1;a %= p;while (b) {if (b & 1) res = res * a % p;a = a * a % p;b >>= 1;}return res;}
ll ksm(ll a, ll b) { ll res = 1; for (; b; b >>= 1, a *= a) if (b & 1) res *= a; return res; }
struct DSU {
    vector<int> parent;
    vector<int> sz; // 存储每个连通块的大小
	vector<int> edges;

    DSU(int n) {
        parent.resize(n + 1);
        iota(parent.begin(), parent.end(), 0); // 初始时父亲是自己
        sz.assign(n + 1, 1); // 初始时每个块大小为 1
		edges.resize(n + 1,0);
    }

    // 路径压缩查找
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    // 按大小合并（可选）或普通合并
    void unite(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            // 将节点数少的树合并到节点数多的树上
            if (sz[rootX] < sz[rootY]) swap(rootX, rootY);
            parent[rootY] = rootX;
            sz[rootX] += sz[rootY];
			edges[rootX] += edges[rootY] + 1;
        }
		else{
			edges[rootX]++;
		}
    }

    int getSize(int x) {
        int r = find(x);
		if(edges[r] == sz[r]) return sz[r] / 2;
		return (sz[r] + 1) / 2;
    }
};
void solve(){
	// ll ans = 0,tmp = 0,cnt = 0,ret = 0,sum = 0;
	
	int n;
	cin >> n;

	vi a(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	vi p(n + 1),r(n + 1);
	for(int i = 1;i <= n;i++){
		cin >> p[i];
		r[p[i]] = i;
	}

	vi id(n);
	iota(all(id),1);
	sort(all(id),[&](int x,int y){
		return a[x] > a[y];
	});

	DSU dsu(n);
	vector<bool> vis(n + 1,0);

	ll tot = 0,ans = 0;
	for(auto x : id){
		vis[x] = 1;
		tot += 1;

		vi tmp;
		if(vis[p[x]]) tmp.pb(p[x]);
		if(vis[r[x]] and r[x] != p[x]) tmp.pb(r[x]);

		for(int v : tmp){
			int rx = dsu.find(x),rv = dsu.find(v);
			if(rx != rv){
				tot -= dsu.getSize(rx);
				tot -= dsu.getSize(rv);
				dsu.unite(x,v);
				tot += dsu.getSize(x);
			}
			else{
				tot -= dsu.getSize(rx);
				dsu.unite(x,v);
				tot += dsu.getSize(x);
			}
		}
		ans = max(ans,tot * a[x]);
	}

	cout << ans << endl;
}

Master Forest_5326()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int _ = 1;
	// cin >> _;
	while(_--){
		solve();
	}
	return 0;
} 
/*振翅岂为枝头驻，落地成灰不回首。*/
/*
  ____    _____    _____    ____  
 | ___|  |___  |  |___  |  | ___| 
 | |__    ___| |   ___| |  | |__  
 |___ \  |___  |  |  ___|  |  _ \ 
  ___| |  ___| |  | |___   | |_| |
 |____/  |_____|  |_____|  \____/
*/
