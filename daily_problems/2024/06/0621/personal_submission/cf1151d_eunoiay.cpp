#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	
	vector<int> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i] >> b[i];
	}

	vector<int> o(n);
	iota(o.begin(), o.end(), 0);
	sort(o.begin(), o.end(), [&](int i, int j) {
		return a[i] - b[i] < a[j] - b[j];
	});

	i64 ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += 1LL * (a[o[i]] - b[o[i]]) * (n - 1 - i);
		ans += 1LL * b[o[i]] * (n - 1);
	}
	cout << ans << "\n";

	return 0;
}
