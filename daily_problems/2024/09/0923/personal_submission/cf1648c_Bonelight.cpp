/*
	Bonelight * V *
	20240923 I'm sad, How 2013/F2
	Not Coding - No Bug
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define endl '\n'
#define pii pair<int, int>
#define INF (int)2e14

template<class T> 
class Tr_N{
	public:
		int n;
		vector<int> tr;

		Tr_N(){};
		Tr_N(int _n): n(_n), tr(_n){}

		void add(int idx, int v){
			idx++;
			while(idx <= n){
				tr[idx - 1] += v;
				idx += idx & -idx; 
			}
		}
		
		T sum(int l, int r){ // [l,r)
			assert(0 <= l && l <= r && r <= n);
			return sum(r) - sum(l);
		}
		
		T sum(int idx){
			T res = 0;
			while(idx > 0){
				res += tr[idx - 1];
				idx -= idx & -idx;
			}
			return res;
		}
};

void solve(){
	const int N = 2e5 + 50, mo = 998244353;
	vector<int> mul(N + 1, 1), ni(N + 1, 1);
#pragma region 
	auto M = [&](int x){
		return (x % mo + mo) % mo;
	};
	auto mypow = [&](int x, int y){
		int res = 1; 
		while(y > 0){
			if(y & 1) res = res * x % mo; 
			x = x*x%mo; 
			y >>= 1;
		}
		return res;
	};
	auto div = [&](int x){return M(mul[x - 1] * ni[x]);};
#pragma endregion
	for(int i = 1; i <= N; i ++) mul[i] = i * mul[i - 1] % mo;
	ni[N] = mypow(mul[N], mo - 2);
	for(int i = N; i >= 1; i --) ni[i - 1] = i * ni[i] % mo;

	int n,m; cin >> n >> m;
	vector<int> cnt(N);
	Tr_N<int> tr(N);

	for(int i = 0, x; i < n; i ++) cin >> x, cnt[x]++, tr.add(x,1);

	int cur = mul[n];
	for(auto i:cnt) cur = M(cur * ni[i]);
	int ans = 0;
	for(int i = 0, x; i < m; i ++){
		cin >> x;
		if(i >= n){ // 前缀全满足, 1 种
			ans = M(ans + 1);
			break;
		}
		cur = cur * div(n - i) % mo;
		ans = M(ans + M(cur * tr.sum(0,x)));
		if(cnt[x] == 0) break;
		cur = M(cur * cnt[x]);
		cnt[x] --;
		tr.add(x, -1);
	}
	cout << ans << endl;
}

signed main(){
#ifndef ONLINE_JUDGE
	freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);

	int T = 1; 
	while(T --){
		solve();
	}
}
