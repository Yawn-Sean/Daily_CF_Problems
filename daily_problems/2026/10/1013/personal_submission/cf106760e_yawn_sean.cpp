#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;
#include "atcoder/segtree.hpp"

using namespace std;

int op(int x, int y) {return max(x, y);}

int e() {return 0;}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n), pos(n + 1);

		for (int i = 0; i < n; i ++) {
			cin >> nums[i];
			pos[nums[i]] = i;
		}

		vector<int> dp0(n, 0);
		atcoder::segtree<int, op, e> seg(n);

		for (int i = 1; i <= n; i ++) {
			int p = pos[i];
			dp0[p] = seg.prod(0, p) + 1;
			
			int v = dp0[p];
			if (p + 1 < n && nums[p] > nums[p + 1]) v = max(v, dp0[p + 1] + 1);
			seg.set(p, v);
		}

		cout << seg.all_prod() << '\n';
	}

	return 0;
}