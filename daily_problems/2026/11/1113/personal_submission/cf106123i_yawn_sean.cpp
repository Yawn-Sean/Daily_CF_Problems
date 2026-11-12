#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, m;
	cin >> n >> m;

	long long ans = 0;

	for (int i = 1; i < n; i ++) {
		for (int j = 1; j < m; j ++) {
			if (gcd(i, j) == 1) {
				int x = min(i, n - i), y = min(j, m - j);
				ans += x * (m - j) + (n - i) * y - x * y; 
			}
		}
	}

	cout << ans;

	return 0;
}