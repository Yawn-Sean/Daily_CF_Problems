#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, r;
	cin >> n >> r;

	int t, c;
	cin >> t >> c;

	long long g = 0;
	int mx = c;

	for (int i = 0; i < n - 1; i ++) {
		int nt, nc;
		cin >> nt >> nc;

		g = gcd(g, abs(1ll * (nt - t) * r - (nc - c)));
		mx = max(mx, nc);
	}

	if (!g) cout << mx + 1;
	else {
		long long inf = 1e18;
		long long ans = inf;

		for (long long i = 1; i <= 1'000'005; i ++) {
			if (g % i == 0) {
				if (i > mx) ans = min(ans, i);
				if (g / i > mx) ans = min(ans, g / i);
			}
		}

		cout << (ans < inf ? ans : -1);
	}

	return 0;
}