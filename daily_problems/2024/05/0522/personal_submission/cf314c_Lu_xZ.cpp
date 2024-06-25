#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 1e6 + 5, P = 1e9 + 7;

ll t[N];

void add(int p, ll v) {
	while(p <= 1e6) {
		t[p] = (t[p] + v) % P;
		p += p & -p;
	}
}
ll sum(int p) {
	ll ret = 0;
	while(p) {
		ret = (ret + t[p]) % P;
		p -= p & -p;
	}
	return ret;
}
int n, lst[N];


int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n;
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		ll tmp = ((sum(x) + 1)* x) % P; 
		add(x, tmp - lst[x]);
		lst[x] = tmp;
	}
	ll ans = sum(1e6);
	if(ans < 0) ans += P;
	cout << ans;
	return 0;
}
