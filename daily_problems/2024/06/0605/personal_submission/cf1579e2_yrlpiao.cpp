#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
#define int long long

int tree[1 << 18];
void update(int i) {
	while (i <= 2e5) {
		tree[i] += 1;
		i += i & -i;
	}
}
int get(int i) {
	int ret = 0;
	while (i) {
		ret += tree[i];
		i -= i & -i;
	}
	return ret;
}
void solve() {
	int n; cin >> n;
	vector<int> a(n), b(n);
	for (int i = 0; i < n; i++) cin >> a[i], b[i] = a[i];
	sort(b.begin(), b.end());
	b.erase(unique(b.begin(), b.end()), b.end());
	memset(tree, 0, sizeof tree);
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int id = lower_bound(b.begin(), b.end(), a[i]) - b.begin() + 1;
		int x = get(id - 1), y = i - get(id);
		ans += min(x, y);
		update(id);
	}
	cout << ans << endl;
}
signed main() {
	int t = 1; cin >> t;
	while (t--) solve();
}
