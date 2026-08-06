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

void solve(){
	ll ans = 0,tmp = 0,cnt = 0,ret = 0,sum = 0;
	
	ll n,q;
	cin >> n >> q;

	vi div;
	for(int i = 1;i * i <= n;i++){
		if(n % i == 0){
			div.pb(i);
			if(i * i != n) div.pb(n / i);
		}
	}


	vvll add(n + 1);
	for(int g : div){
		add[g].resize(g,0);
	}

	while(q--){
		ll fir,stp,cst;
		cin >> fir >> stp >> cst;

		ll g = gcd(stp,n);
		ll r = (fir - 1) % g;

		add[g][r] += cst;
	}

	ll mx = -inf;
	ans = 1;
	for(int i = 0;i < n;i++){
		ll tot = 1;
		for(int g : div){
			tot += add[g][i % g];
		}
		if(tot > mx){
			mx = tot;
			ans = i + 1;
		}
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
