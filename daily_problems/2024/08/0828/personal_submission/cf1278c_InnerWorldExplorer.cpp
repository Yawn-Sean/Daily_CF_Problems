#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

void solve() {
	int n;
	cin >> n;
	vector<int> a(n), b(n);
	map<int, int> m;
	int cur = 0;
	for (int i = n - 1; i >= 0; i --) {
		cin >> a[i];
		cur += (a[i] == 1) ? 1 : -1;
		m[cur] = n - i;
	}
	for (int i = 0; i < n; i ++) {
		cin >> b[i];
	}
	cur = 0;
	int ans = m[0];
	for (int i = n - 1; i >= 0; i --) {
		cur += (b[i] == 1) ? 1 : -1;
		if (m.count(-cur))
			ans = max(ans, m[-cur] + n - i);
	}
	cout << 2 * n - ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int T;
	cin >> T;
	while (T -- ) {
		solve();
	}
	return 0;
}
