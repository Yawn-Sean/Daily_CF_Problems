#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	i64 n, L;
	cin >> n >> L;
	vector<i64> a(n * 2 + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		a[i + n] = a[i];
	}

	sort(a.begin() + 1, a.begin() + n + 1);
	sort(a.begin() + n + 1, a.end());

	i64 ans = n * (n - 1) * (n - 2) / 6;
	i64 l = 1;
	for (i64 r = n + 1; r <= n * 2; r++) {
		while (l < r && (l <= n && (L - (a[l] - a[r])) * 2 >= L || l > n && (a[r] - a[l]) * 2 >= L)) {
			l++;
		}

		ans -= (r - l) * (r - l - 1) / 2;
	}

	cout << ans;
	return 0;
}