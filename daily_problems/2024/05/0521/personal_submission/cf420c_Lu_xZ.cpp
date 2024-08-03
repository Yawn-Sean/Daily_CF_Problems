#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 3e5 + 5;

int n, m, cnt[N];
ll ans;
map<int, map<int, int>> mp;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m;
	
	for(int i = 1; i <= n; ++ i) {
		int x, y; cin >> x >> y;
		++ cnt[x];
		++ cnt[y];
		if(x > y) swap(x, y);
		++ mp[x][y];
	}
	for(auto [x, mpx] : mp) {
		for(auto [y, cc] : mpx) {
			if(cnt[x] + cnt[y] >= m && cnt[x] + cnt[y] < m + cc) {
				-- ans;
			}
		}
	}
	sort(cnt + 1, cnt + n + 1);
	for(int i = 1; i <= n; ++ i) {
		int p = lower_bound(cnt + i + 1, cnt + n + 1, m - cnt[i]) - cnt;
		ans += max(n - p + 1, 0);
	}
	cout << ans;
	return 0;
}
