#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")
#include "atcoder/segtree"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

typedef pair<int, bool> node;

typedef pair<node, node> seg_node;

seg_node op(seg_node u1, seg_node u2) {
	auto [first1, second1] = u1;
	auto [xfirst1, yfirst1] = first1;
	auto [xsecond1, ysecond1] = second1;

	auto [first2, second2] = u2;
	auto [xfirst2, yfirst2] = first2;
	auto [xsecond2, ysecond2] = second2;

	int xfirst, yfirst, xsecond, ysecond;

	if (!yfirst1) {
		xfirst = xfirst1 + xfirst2;
		yfirst = yfirst2;
	}
	else {
		xfirst = xfirst1 + xsecond2;
		yfirst = ysecond2;
	}

	if (!ysecond1) {
		xsecond = xsecond1 + xfirst2;
		ysecond = yfirst2;
	}
	else {
		xsecond = xsecond1 + xsecond2;
		ysecond = ysecond2;
	}

	return {{xfirst, yfirst}, {xsecond, ysecond}};
}

seg_node e() {return {{0, 0}, {0, 1}};}

seg_node win() {return {{1, 0}, {1, 0}};}

seg_node lose() {return {{0, 1}, {0, 1}};}

seg_node draw() {return {{1, 0}, {0, 1}};}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> vs1(n + m), vs2(n + m);
	vector<string> cs1(n + m), cs2(n + m);

	map<string, vector<int>> d;

	for (int i = 0; i < n + m; i ++) {
		cin >> vs1[i] >> cs1[i] >> vs2[i] >> cs2[i];

		if (d.find(cs1[i]) == d.end()) auto x = d[cs1[i]];
		if (d.find(cs2[i]) == d.end()) auto x = d[cs2[i]];

		if (cs1[i] != cs2[i]) {
			d[cs1[i]].emplace_back(i);
			d[cs2[i]].emplace_back(~i);
		}
	}

	vector<seg_node> seg_vec(n + m);

	for (int i = 0; i < n + m; i ++) {
		if (cs1[i] == cs2[i]) seg_vec[i] = vs1[i] > vs2[i] ? win() : lose();
		else seg_vec[i] = draw();
	}

	atcoder::segtree<seg_node, op, e> seg(seg_vec);

	for (auto &[x, v]: d) {
		for (auto &idx: v) {
			if (idx >= 0) seg.set(idx, win());
			else seg.set(~idx, lose());
		}

		if (seg.all_prod().first.first == n)
			return cout << x, 0;

		for (auto &idx: v) {
			if (idx >= 0) seg.set(idx, draw());
			else seg.set(~idx, draw());
		}
	}

	cout << '*';

	return 0;
}