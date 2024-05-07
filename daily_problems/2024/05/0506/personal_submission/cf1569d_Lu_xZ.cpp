#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 2e5 + 5;

int n, m, k, X[N], Y[N];

void solve() {
	int n, m, k; cin >> n >> m >> k;
	
	for(int i = 0; i < n; ++ i) cin >> X[i];
	for(int i = 0; i < m; ++ i) cin >> Y[i];
	
	map<int, map<int, int>> cx, cy;
	map<int, int> tx, ty;
	
	ll ans = 0;
	
	for(int i = 0; i < k; ++ i) {
		int x, y; cin >> x >> y;
		
		bool vx = binary_search(X, X + n, x);
		bool vy = binary_search(Y, Y + m, y);
		
		if(vx && vy) continue;
		
		if(vx) {
			int py = lower_bound(Y, Y + m, y) - Y;
			/*
			  py 相同，x不同
			 */
			ans += ty[py] ++;
			ans -= cx[x][py] ++;
		}
		else {
			int px = lower_bound(X, X + n, x) - X;
			/*
			  px 相同，y不同
			 */
			ans += tx[px] ++;
			ans -= cy[px][y] ++;
		}
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
