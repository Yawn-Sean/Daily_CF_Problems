#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
#define All(X) X.begin(), X.end()
using namespace std;
using ll = long long;


void solve() {
	int n, x, y; cin >> n >> x >> y;
	vector a(n + 1, 0);
	for(int i = 1; i <= n; ++ i) {
		int a; cin >> a;
		a %= (x + y);
		ll l = 0, r = (ll)x * y;
		while(l < r) {
			ll mid = l + r >> 1;
			if(mid / x + mid / y >= a) r = mid;
			else l = mid + 1;
		}
		if(l % x == 0 && l % y == 0) cout << "Both\n";
		else if(l % x == 0) cout << "Vova\n";
		else if(l % y == 0) cout << "Vanya\n";
	}
}

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
	while(T --) solve();
	return 0;
}
