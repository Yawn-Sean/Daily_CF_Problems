#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef pair<long long, long long> node;

long long inf = 1e15;

node op(node a, node b) {
	auto [xa, ya] = a;
	auto [xb, yb] = b;
	return {xa + xb, max(ya + xb, yb)};
}

node e() {return {0, -inf};}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n), v2(n);
	for (auto &x: v1) cin >> x;
	for (auto &x: v2) cin >> x;

	vector<node> vec;
	for (int i = 0; i < n; i ++)
		vec.emplace_back(v2[i] - v1[i], v2[i]);

	atcoder::segtree<node, op, e> seg(vec);

	int q;
	cin >> q;

	while (q --) {
		int l, r;
		cin >> l >> r;
		cout << seg.prod(l - 1, r).second << '\n';
	}

	return 0;
}