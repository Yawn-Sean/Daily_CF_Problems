#include<bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= (b); ++ i)
#define per(i, a, b) for(int i = (a); i >= (b); -- i)
#define pb emplace_back
using namespace std;
using ll = long long;

void solve() {
	int n; cin >> n;
	map<tuple<int, int, int>, int> mp;
	ll ans = 0;
	for(int i = 1; i <= n; ++ i) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if(a == c) {
			ans += mp[make_tuple(0, 1, b > d)];
			++ mp[make_tuple(0, 1, b < d)];
		}
		else if(b == d) {
			ans += mp[make_tuple(1, 0, a > c)];
			++ mp[make_tuple(1, 0, a < c)];
			
		}
		else {
			int dx = a - c;
			int dy = b - d;
			int r = __gcd(dx, dy);
			dx /= r;
			dy /= r;
			if(dx < 0) {
				dx = -dx;
				dy = -dy;
			}
			ans += mp[make_tuple(dx, dy, a > c)];
			++ mp[make_tuple(dx, dy, a < c)];
		}
	}
	cout << ans << '\n';
}

/*
统计多少对反向平行的线段
*/

int main() {
	ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int T = 1;
	cin >> T;
	while(T --) solve();
	return 0;
}
