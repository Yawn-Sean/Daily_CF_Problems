#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	mt19937 rng(random_device{}());

	int k, n;
	cin >> k >> n;

	uniform_int_distribution<long long> gen1(1, 1ll * k * (k + 1) / 2);
	uniform_int_distribution<int> gen(1, k);

	while (n --) {
		if (gen1(rng) <= k) {
			int x = gen(rng);
			cout << x << ' ' << x << '\n';
		}
		else {
			while (true) {
				int x = gen(rng);
				int y = gen(rng);
				if (x < y) {
					cout << x << ' ' << y << '\n';
					break;
				}
			}
		}
	}

	return 0;
}