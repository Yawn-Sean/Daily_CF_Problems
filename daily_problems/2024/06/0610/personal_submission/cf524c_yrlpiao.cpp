#include <iostream>
#include <map>
using namespace std;

int arr[1 << 20] {};
map<int, int> mp;
void yrlpSolve() {
    int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		for (int j = 1; j <= k; j++) mp[arr[i] * j] = j;
	}
	int q; cin >> q;
	mp[0] = 0;
	while (q--) {
		int x; cin >> x;
		int ans = 1e9;
		for (auto y : mp) {
			if (mp.count(x - y.first)) {
				ans = min(ans, mp[x - y.first] + y.second);
			}
		}
		cout << (ans > k ? -1 : ans) << endl;
	}
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
