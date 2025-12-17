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

	int pt = 0, M = 1e6 + 10;

	vector<int> pos(M, -1), prev_pos(M, -1), next_pos(M, -1);

	auto delete_node = [&] (int x) -> void {
		int p = pos[x];
		next_pos[prev_pos[p]] = next_pos[p];
		prev_pos[next_pos[p]] = prev_pos[p];
		pos[x] = -1;
	};

	auto insert_node = [&] (int y, int x) -> void {
		pos[x] = ++pt;
		int p = pos[x], q = pos[y];

		prev_pos[p] = prev_pos[q];
		next_pos[p] = q;

		prev_pos[next_pos[p]] = p;
		next_pos[prev_pos[p]] = p;
	};

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &x: nums) cin >> x;

	pos[nums.back()] = 0;
	next_pos[0] = 0;
	prev_pos[0] = 0;

	int cur = nums.back();
	for (int i = n - 2; i >= 0; i --) {
		insert_node(cur, nums[i]);
		cur = nums[i];
	}

	int q;
	cin >> q;

	while (q --) {
		char op;
		cin >> op;

		if (op == '-') {
			int v;
			cin >> v;
			delete_node(v);
		}
		else if (op == '+') {
			int x, y;
			cin >> x >> y;
			insert_node(y, x);
		}
		else {
			int k;
			cin >> k;

			vector<int> vals(k);
			for (auto &x: vals) cin >> x;

			int ans = 0, res = 0;
			for (int i = 0; i < k * 2; i ++) {
				if (pos[vals[i % k]] == -1) res = 0;
				else if (prev_pos[pos[vals[i % k]]] == pos[vals[(i + k - 1) % k]]) res ++;
				else res = 1;
				ans = max(ans, res);
			}
			
			if (ans < k * 2) cout << ans << '\n';
			else cout << '*' << '\n';
		}
	}

	return 0;
}