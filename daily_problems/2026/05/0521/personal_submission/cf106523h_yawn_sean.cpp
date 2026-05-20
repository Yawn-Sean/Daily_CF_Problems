#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int M = 1e5 + 5;
	vector<int> pr(M);

	iota(pr.begin(), pr.end(), 0);
	
	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
			}
		}
	}

	int q;
	cin >> q;

	vector<long long> cur(M, 0);
	vector<int> to_multiply;

	while (q --) {
		int t, x;
		cin >> t >> x;

		if (t == 1) {
			while (x > 1) {
				if (!cur[pr[x]])
					to_multiply.emplace_back(pr[x]);
				cur[pr[x]] ++;
				x /= pr[x];
			}
		}
		else if (t == 2) {
			vector<int> new_to_multiply;

			for (auto &v: to_multiply) {
				cur[v] *= x;
				if (cur[v] < 20) new_to_multiply.emplace_back(v);
			}

			to_multiply.swap(new_to_multiply);
		}
		else {
			int v = x;
			bool flg = true;

			while (v > 1) {
				if (!cur[pr[v]]) flg = false;
				cur[pr[v]] --;
				v /= pr[v];
			}

			v = x;
			while (v > 1) {
				cur[pr[v]] ++;
				v /= pr[v];
			}

			cout << (flg ? "Yes" : "No") << '\n';
		}
	}

	return 0;
}