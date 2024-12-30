#include <iostream>
#include <vector>
#include <array>
#include <cstring>
#include <algorithm>
using namespace std;
#define ar2 array<int, 2>

int arr[1 << 18] {};
int ind[1 << 18] {};
int cnt[1 << 18] {};
int vis[1 << 18] {};
void solve() {
	int n; cin >> n >> arr[0];
	for (int i = 1; i <= n; i++) cin >> arr[i];
	for (int i = n; i >= 1; i--) {
		ind[arr[i]] = ind[arr[i]] ? ind[arr[i]] : i;
	}
	vector<ar2> v;
	for (int i = 1; i <= n; i++) {
		if (vis[arr[i]]) continue;
		v.push_back({i, ind[arr[i]]});
		vis[arr[i]] = 1;
	}
	v.push_back({(int)2e9, 0});
	int st = 1, ed = 1, ans = 0;
	for (ar2 x : v) {
		if (ed >= x[0]) {
			ed = max(ed, x[1]);
		} else {
			int ma = 0;
			memset(cnt, 0, sizeof cnt);
			for (int j = st; j <= ed; j++) {
				cnt[arr[j]] += 1;
				ma = max(ma, cnt[arr[j]]);
			}
			ans += ed - st + 1 - ma;
			st = x[0], ed = x[1];
		}
	}
	cout << ans;
}
signed main() {
	int t = 1; //cin >> t;
	while (t--) solve();
}
