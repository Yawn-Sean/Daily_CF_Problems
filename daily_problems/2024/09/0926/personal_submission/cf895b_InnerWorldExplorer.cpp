#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

void solve() {
	int n, d, cnt;
	cin >> n >> d >> cnt;
	vector<int> a(n);
	for (auto &x : a) {
		cin >> x;
	}
	sort(a.begin(), a.end());
	i64 ans = 0;
	for (auto &x : a){
		int v = (x - 1) / d + cnt;
		ans += lower_bound(a.begin(), a.end(), 1LL * (v + 1) * d) - lower_bound(a.begin(), a.end(), max<i64>(1LL * x, 1LL * v * d));
	}
	cout << ans << endl;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	solve();
	return 0;
}
