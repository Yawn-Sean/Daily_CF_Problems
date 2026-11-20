#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		unsigned int x, y, n;
		cin >> x >> y >> n;

		unsigned int total = x + y * 2;

		if (total % n == 0) {
			if (total / n % 2 * n <= x) {
				cout << 0 << '\n';
				continue;
			}
		}
		else {
			unsigned int a = total / n, b = total % n;

			if (a % 2 * (n - b) + (a + 1) % 2 * b <= x) {
				cout << 1 << '\n';
				continue;
			}
		}

		cout << 2 << '\n';
	}

	return 0;
}