#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<i64> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	i64 res = 0;
	i64 cur = 1LL << n - 1;
	vector<i64> ans(n + 1);
	for (int i = 1; i <= n; i++) {
		if (a[i]) {
			ans[i] = cur * a[i];
			res += cur;
			cur >>= 1;
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!a[i]) {
			ans[i] = cur;
			cur >>= 1;
		}
	}

	cout << res << "\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}