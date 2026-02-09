#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	auto query = [&] (int i, int j) -> int {
		cout << "? " << i << ' ' << j << endl;
		int x; cin >> x;
		return x;
	};

	int idx = -1;
	bool flg = false;

	for (int i = 0; i < n; i ++) {
		if (query(0, i) == n) {
			if (idx != -1) flg = true;
			idx = i;
		}
	}

	if (!flg) {
		int to_query = (idx ? idx - 1 : 1);

		for (int i = 0; i < n; i ++) {
			if (query(i, to_query) == n) {
				cout << "! " << (idx - i + n) % n;
				break;
			}
		}
	}
	else {
		for (int i = 0; i < n; i ++) {
			if (query(1, i) == n) {
				cout << "! " << i;
				break;
			}
		}
	}

	return 0;
}