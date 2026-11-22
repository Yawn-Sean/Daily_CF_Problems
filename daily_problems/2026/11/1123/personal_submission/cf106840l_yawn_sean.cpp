#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	long double pi = acosl(-1);
	cout << fixed << setprecision(15);

	while (t --) {
		int a, b;
		cin >> a >> b;
		if (a < b) swap(a, b);

		if (a == b || 360 % (a - b)) cout << -1 << '\n';
		else {
			int n = 360 / (a - b);
			long double area = 0;
			area += sinl(pi * a / 180) / 2;
			area += cosl(pi * a / 2 / 180) * cosl(pi * a / 2 / 180) / tanl(pi / n);
			cout << area * n << '\n';
		}
	}

	return 0;
}