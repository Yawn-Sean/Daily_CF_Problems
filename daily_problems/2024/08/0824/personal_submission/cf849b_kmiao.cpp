#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define endl '\n'
const double eps = 1e-7;

void solve() {
	int n;
	cin >> n;
	vector<double> y(n);
	rep(i, 0, n)
		cin >> y[i];

	auto f = [&](int i, int j) -> bool {
		double a = (y[j] - y[i]) / (j - i);
		double b = y[j] - a * j;

		double sec = false;
		double a2 = a, b2;

		for (int k = 0; k < n; k++) {
			if (k == i || k == j) continue;
			if ( fabs(a * k + b - y[k]) > eps ) {
				if (sec && ( fabs(a2 * k + b2 - y[k]) > eps ) ) {
					return false;
				}
				if (!sec) {
					b2 = y[k] - a2 * k;
					sec = true;
				}
			}
		}
		return sec;
	};

	if (f(0, 1) || f(0, 2) || f(1, 2)) cout << "Yes" << endl;	
	else cout << "No" << endl;
}

int main() {
    cin.tie(0)->sync_with_stdio(false);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
