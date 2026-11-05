#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	cout << fixed << setprecision(0);

	while (t --) {
		long double d1, d2;
		cout << "? 1 0" << endl;
		cin >> d1;
		cout << "? 1 1" << endl;
		cin >> d2;

		long double d = sqrtl(d1 * d1 + d2 * d2 - sqrt(2) * d1 * d2);
		long double h = d1 * d2 * sqrtl(2) / 2 / d;

		cout << "! " << 4 * h * h << endl;
	}

	return 0;
}