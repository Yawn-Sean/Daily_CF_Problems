#include<bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
	ll n; cin >> n;
	string s; cin >> s;
	
	ll ans = n * n;
	
	int p = 0;
	while(p + 1 < s.length() && s[p] == s[p + 1]) ++ p;
	
	if(p == s.length() - 1) {
		cout << n << '\n';
		return;
	}
	
	ans -= (n - 1) * (p + 1);

	ll x = 1, y = 1;
	while(++ p < s.length()) {
		if(s[p] == 'D') {
			++ x;
		}
		else {
			++ y;
		}
	}
	ans -= (x - 1) * (y - 1);
	cout << ans << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T;
	cin >> T;
	
	while(T --) {
		solve();
	}
	return 0;
}
