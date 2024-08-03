#include<bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n; cin >> n;
	vector<int> cnt(n + 1, 0);
	
	for(int i = 1; i <= n; ++ i) {
		int x; cin >> x;
		++ cnt[x];
	}
	
	vector<int> ccnt(n + 1, 0);
	vector<int> a;
	ll ans = 0;
	
	for(int i = 1; i <= n; ++ i) {
		++ ccnt[cnt[i]];
		ans += cnt[i];
	}
	for(int i = 1; i <= n; ++ i) {
		if(ccnt[i]) {
			a.push_back(i);
		}
	}
	
	for(int i = 1; i <= a.front() + 1; ++ i) {
		int ok = 1;
		ll tmp = 0;
		for(int x : a) {
			ll j = x / i + (x % i != 0);
			if(j * i - x > j) {
				ok = 0;
				break;
			}
			tmp += j * ccnt[x];
		}
		if(ok) ans = min(ans, tmp);
	}
	
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
