#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	long long c = 0, mn = *min_element(a.begin(), a.end()), mx = (*max_element(a.begin(), a.end()));

	for (int i = 0; i + 1 < n; ++i) {
		int l = min(a[i], a[i + 1]), r = max(a[i], a[i + 1]);
		c += r - l;
	}
	if (x > mx) {
		ll s1 = 1e18;
		for (int i = 0; i <= n; ++i) {
			long long cu = c;
			if (i > 0) {
				cu += x - a[i - 1];
			}
			if (i < n) {
				cu += x - a[i];
			}

			if (i > 0 && i < n) {
				cu -= abs(a[i] - a[i - 1]);
			}
			s1 = min(s1, cu);
		}
		c = s1;
	}

	if (1 < mn) {
		ll s1 = 1e18;
		for (int i = 0; i <= n; ++i) {
			long long cu = c;
			if (i > 0) {
				cu += a[i - 1] - 1;
			}
			if (i < n) {
				cu += a[i] - 1;
			}

			if (i > 0 && i < n) {
				cu -= abs(a[i] - a[i - 1]);
			}
			s1 = min(s1, cu);
		}
		c = s1;
	}

	cout << c << "\n";

}

int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    
    int t;
    cin >> t;
    while (t--) {
    	solve();
    }

    return 0;
}
