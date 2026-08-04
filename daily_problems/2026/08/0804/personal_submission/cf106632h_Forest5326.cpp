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
	
	int n;
	cin >> n;
	multiset<int> s;
	for(int i = 0;i < n;i++){
		int x;
		cin >> x;
		s.insert(x);
	}

	vector<PII> p(n);
	for(int i = 0;i < n;i++){
		cin >> p[i].fi;
		p[i].se = i + 1;
	}
	sort(rall(p));

	for(int i = 0;i < n;i++){
		auto it = s.upper_bound(p[i].se);
		if(it != s.begin()){
			--it;
			ans += p[i].fi;
			s.erase(it);
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
	cin >> _;
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
