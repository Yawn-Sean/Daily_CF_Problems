#include <bits/stdc++.h>
using namespace std;
#define int long long
#define debug(x) cerr << #x << " = " << (x) << endl
#define debugv(v) { cerr << #v << " = [ "; for (auto x : v) cerr << x << " "; cerr << "]" << endl; }
#define all(x) (x).begin(),(x).end()
void solve();
#define endl '\n'

#define fi first
#define se second


const long long INF = 0x3f3f3f3f;
const long long MOD = 1e9; //模数
// const int N = 2e5 + 10;

signed main (){ 
	std::cin.tie(NULL)->sync_with_stdio(false);
	int t = 1;
	// cin >> t;  //atc默认关闭，cf按需开启
	while(t --)
		solve();
}
 				// TIME limit 4000 ms

void solve(){
	int n;
	cin >> n;
	if(n < 3){
		cout << 0 << endl;
		return;
	}
	vector<pair<int, int> > p;
	for(int i = 0; i < n; i ++){
		int x, y;
		cin >> x >> y;
		p.push_back({x, y});
	}
	int ans = 1LL * n * (n - 1) * (n - 2) / 6;
	for(int i = 0; i < n; i ++){
		map<pair<int, int>, int> cnt;
		for(int j = 0; j < i; j ++){
			int x = p[j].fi - p[i].fi; //改了五遍一直wa T4, 最后发现是p[i].fi写成p[i].se了，草！
			int y = p[j].se - p[i].se; ////计算向量，但是要保留最简用于计算数量
			int chu = __gcd(x, y);
			x /= chu, y /= chu;
			if(x < 0)
				x = -x, y = -y;
			else if(x == 0 and y < 0)
				x = -x, y = -y;
			ans -= cnt[{x, y}];
			cnt[{x, y}] ++;
		}
	}
	cout << ans << endl;
}
