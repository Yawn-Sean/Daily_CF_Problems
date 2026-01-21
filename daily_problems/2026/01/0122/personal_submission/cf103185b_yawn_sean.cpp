#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
#include "atcoder/lazysegtree"

int e() {return -1;}

int op(int x, int y) {return max(x, y);}

int add(int x, int y) {return x + y;}

int id() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e6;
	vector<int> ar(M + 1);
	for (int i = 0; i <= M; i ++) ar[i] = -i - 1;
	atcoder::lazy_segtree<int, op, e, int, add, add, id> seg(ar);

	int q;
	cin >> q;

	while (q --) {
		int t, x;
		cin >> t >> x;
		if (t == 1) seg.apply(x, M + 1, 1);
		else seg.apply(x, M + 1, -1);
		cout << seg.min_left(M + 1, [&] (int x) {return x < 0;}) << '\n';
	}

	return 0;
}