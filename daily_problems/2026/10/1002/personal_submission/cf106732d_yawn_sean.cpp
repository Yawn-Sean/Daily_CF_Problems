#include <bits/stdc++.h>
#include "atcoder/fenwicktree.hpp"
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l, r, mod = 998244353;
	cin >> n >> l >> r;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	r ++;

	vector<int> v1(l, 0), v2(r, 0);
	int p1 = 0, p2 = 0;
	int c1 = 0, c2 = 0;

	atcoder::fenwick_tree<long long> fen(n + 1);
	fen.add(0, 1);

	for (int i = 0; i < n; i ++) {
		if (nums[i] < l) {
			if (!v1[nums[i]]) c1 ++;
			v1[nums[i]] ++;
		}

		if (nums[i] < r) {
			if (!v2[nums[i]]) c2 ++;
			v2[nums[i]] ++;
		}

		while (p1 <= i && c1 == l) {
			if (nums[p1] < l) {
				v1[nums[p1]] --;
				if (!v1[nums[p1]]) c1 --;
			}
			p1 ++;
		}

		while (p2 <= i && c2 == r) {
			if (nums[p2] < r) {
				v2[nums[p2]] --;
				if (!v2[nums[p2]]) c2 --;
			}
			p2 ++;
		}

		fen.add(i + 1, fen.sum(p2, p1) % mod);
	}

	cout << fen.sum(n, n + 1);

	return 0;
}