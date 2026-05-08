#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef pair<int, int> node;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<node> shirts(n);
	for (auto &[x, y]: shirts) cin >> x >> y;

	sort(shirts.begin(), shirts.end(), [&] (node &x, node &y) {
		if (x.second > y.second) return true;
		if (x.second < y.second) return false;
		return x.first < y.first;
	});

	int q;
	cin >> q;

	while (q --) {
		int b;
		cin >> b;
	}

	return 0;
}
