#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/fenwicktree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	atcoder::fenwick_tree<long long> fen_x_k(n + 2), fen_x_b(n + 2);
	atcoder::fenwick_tree<long long> fen_y_k(n + 2), fen_y_b(n + 2);

	fen_x_k.add(0, 1);

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int l, r;
			cin >> l >> r;

			if (l == r) continue;

			int x1 = fen_x_k.sum(0, l + 1) * l + fen_x_b.sum(0, l + 1);
			int x2 = fen_x_k.sum(0, r + 1) * r + fen_x_b.sum(0, r + 1);

			if (x1 == x2) {
				fen_x_k.add(l, 1);
				fen_x_k.add(r + 1, -1);

				fen_x_b.add(l, -l);
				fen_x_b.add(r + 1, l);

				fen_y_k.add(l, -1);
				fen_y_k.add(r + 1, 1);

				fen_y_b.add(l, l);
				fen_y_b.add(r + 1, -l);
			}
			else {
				fen_x_k.add(l, -1);
				fen_x_k.add(r + 1, 1);

				fen_x_b.add(l, l);
				fen_x_b.add(r + 1, -l);

				fen_y_k.add(l, 1);
				fen_y_k.add(r + 1, -1);

				fen_y_b.add(l, -l);
				fen_y_b.add(r + 1, l);
			}
		}
		else {
			int j;
			cin >> j;

			cout << fen_x_k.sum(0, j + 1) * j + fen_x_b.sum(0, j + 1) << ' ';
			cout << fen_y_k.sum(0, j + 1) * j + fen_y_b.sum(0, j + 1) << '\n';
		}
	}

	return 0;
}