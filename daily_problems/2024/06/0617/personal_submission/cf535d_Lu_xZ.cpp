#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int N = 1e6 + 5, B1 = 131, B2 = 1145141, P1 = 1e9 + 7, P2 = 998244353;

int n, m, p, lst; ll pw1[N], pw2[N]; char t[N];
string s;

struct Hash {
	ll f[N], g[N];
	void update(int i, char x) {
		f[i] = (f[i - 1] * B1 + x) % P1;
		g[i] = (g[i - 1] * B2 + x) % P2;
	}
	void init(string &s) {
		f[0] = g[0] = s[0];
		for(int i = 1; i < s.length(); ++ i) {
			update(i, s[i]);
		}
	}
	typedef pair<ll, ll> pll;
	pll get(int r) {
		return make_pair(f[r], g[r]);
	}
	pll get(int l, int r) {
		ll x = ((f[r] - f[l - 1] * pw1[r - l + 1]) % P1 + P1) % P1;
		ll y = ((g[r] - g[l - 1] * pw2[r - l + 1]) % P2 + P2) % P2;
		return make_pair(x, y);
	}
	
} T, H;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	pw1[0] = pw2[0] = 1;
	for(int i = 1; i < N; ++ i) {
		pw1[i] = pw1[i - 1] * B1 % P1;
		pw2[i] = pw2[i - 1] * B2 % P2;
	}
	cin >> n >> m >> s;
	p = s.length();
	T.init(s);
	for(int i = 1; i <= m; ++ i) {
		int x;
		cin >> x;
		if(x <= lst) {
			if(T.get(lst - x) != H.get(x, lst)) {
				cout << 0;
				exit(0);
			}
			for(int j = lst + 1; j < x + p; ++ j) {
				t[j] = s[j - x];
				H.update(j, t[j]);
			}
		}
		else {
			for(int j = lst + 1; j < x; ++ j) H.update(j, 0);
			for(int j = x; j < x + p; ++ j) {
				t[j] = s[j - x];
				H.update(j, t[j]);
			} 
		}
		lst = x + p - 1;
	}
	ll ans = 1;
	for(int i = 1; i <= n; ++ i) {
		if(!t[i]) 
			ans = ans * 26 % P1;
	}
	cout << ans;
	return 0;
}
