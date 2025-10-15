#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& x: a) { cin >> x; }
	
	/*
		consider each occurence of
		|ai - 0| & |ai - aj|
		- from i to j
		- from 0 to i
	*/
	i64 tot = 0;
	i64 sm = accumulate(a.begin(), a.end(), 0ll);
	sort(a.begin(), a.end());
	
	i64 preSm = 0;
	for (int i = 0; i < n; i++) {
		tot += a[i];
		// a[i]-a[j]
		tot += 1ll * i * a[i] - preSm;
		i64 sufSm = sm - preSm;
		tot += sufSm - 1ll * (n - i) * a[i];
		preSm += a[i];
	}
	
	i64 base = n;
	i64 g = gcd(tot, base);
	cout << tot / g << ' ' << base / g;
	
	return 0;
}
