#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int X, d; cin >> X >> d;
	vector<ll> ans;
	ll cur = 1;
	for(int i = 0; i <= 30; ++ i) {
		if(X >> i & 1) {
			for(int j = 0; j < i; ++ j) ans.push_back(cur);
			ans.push_back(cur += d);
			cur += d;
		}
	}

	cout << ans.size() << '\n';
	for(auto x : ans) cout << x << ' ';
	return 0;
}
