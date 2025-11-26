#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> nums(n + 1, 0), pos(n + 1, 0);

		for (int i = 1; i <= n; i ++) {
			cin >> nums[i];
			pos[nums[i]] = i;
		}

		vector<vector<int>> ops;

		auto operate = [&] (vector<int> vals) -> void {
			vector<int> vis_idx(n + 1, 0), vis_val(n + 1, 0);

			for (auto &x: vals) {
				vis_idx[pos[x]] = 1;
				vis_val[x] = 1;
			}

			vector<int> nidxs, nvals;

			for (int i = 0; i <= n; i ++) {
				if (vis_idx[i]) nidxs.emplace_back(i);
				if (vis_val[i]) nvals.emplace_back(i);
			}

			for (int i = 0; i < nidxs.size(); i ++) {
				nums[nidxs[i]] = nvals[i];
				pos[nvals[i]] = nidxs[i];
			}

			ops.emplace_back(nidxs);
		};

		auto move_pos = [&] () -> void {
			if (nums[n] == n) return ;
			vector<int> vals = {nums[n], n};
			int cur = nums[n] ^ n;

			while (cur) {
				int x = cur & -cur;
				vals.emplace_back(x);
				cur -= x;
			}

			operate(vals);
		};

		int val = 1 << 31 - __builtin_clz(n);

		if ((n & -n) == n) {
			if (nums[n] != n) {
				cout << -1 << '\n';
				continue;
			}
			else if (n % 4 == 0) {
				vector<int> idxs(n - 1);
				iota(idxs.begin(), idxs.end(), 1);
				operate(idxs);
			}
		}
		else if (n % 4 == 3) {
			vector<int> idxs(n);
			iota(idxs.begin(), idxs.end(), 1);
			operate(idxs);
		}
		else if (n % 4 == 1) {
			vector<int> idxs1(n - 2), idxs2(n - 1);
			iota(idxs1.begin(), idxs1.end(), 1);
			iota(idxs2.begin(), idxs2.end(), 2);
			operate(idxs1);
			operate(idxs2);
			operate(idxs1);
		}
		else if (n % 4 == 0) {
			vector<int> idxs1(val - 1), idxs2(n - 1);
			iota(idxs1.begin(), idxs1.end(), 1);
			iota(idxs2.begin(), idxs2.end(), 1);
			operate(idxs1);
			move_pos();
			operate(idxs2);
		}
		else {
			vector<int> idxs1(val - 1), idxs2(n - 3), idxs3(n - 2);
			iota(idxs1.begin(), idxs1.end(), 1);
			iota(idxs2.begin(), idxs2.end(), 1);
			iota(idxs3.begin(), idxs3.end(), 2);
			operate(idxs1);
			move_pos();
			operate(idxs2);
			operate(idxs3);
			operate(idxs2);
		}

		cout << ops.size() << '\n';
		for (auto &op: ops) {
			cout << op.size();
			for (auto &x: op) cout << ' ' << x;
			cout << '\n';
		}
	}

	return 0;
}