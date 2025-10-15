#include <bits/stdc++.h>
using LL = long long;
using namespace std;

void solve() {
	
	LL n,k;
	cin >> n >> k;

	if (n < k) {
		cout << "NO\n";
		return;
	}

	if (n == k) {
		cout << "YES\n1\n1\n";
		return;
	}

	if (2 * (n - k + 1) > n) {
		cout << "YES\n2\n" << n - k + 1 << " 1\n";
	} else {
		cout << "NO\n";
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}

	return 0;
}
