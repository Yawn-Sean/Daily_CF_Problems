#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		for (int i = 1; i <= 1000; i ++) {
			int v = i * (i + 1) / 2;
			if (n <= v && n >= 2 - v && (n - v) % 2 == 0 && n != v - 2 && n != 4 - v) {
				vector<int> sign(i + 1, 0);
				int target = (v - n) / 2;
				
				for (int x = i; x > 1; x --) {
					if (target >= x && target - x != 1) {
						target -= x;
						sign[x] = 1;
					}
				}

				cout << i << '\n';
				cout << 1;
				for (int x = 2; x <= i; x ++)
					cout << "+-"[sign[x]] << x;
				cout << '\n';
				break;
			}
		}
	}

	return 0;
}