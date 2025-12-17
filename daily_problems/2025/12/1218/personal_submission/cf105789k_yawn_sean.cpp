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

	int n;
	long long p, h;
	cin >> n >> p >> h;

	vector<long long> muls, adds;
	int cnt = 0;

	for (int i = 0; i < n; i ++) {
		char op;
		cin >> op;

		if (op == '*') {
			int x;
			cin >> x;
			if (x > 1) muls.emplace_back(x);
		}
		else if (op == '+') {
			int x;
			cin >> x;
			adds.emplace_back(x);
		}
		else cnt ++;
	}

	sort(muls.rbegin(), muls.rend());
	sort(adds.rbegin(), adds.rend());

	if (cnt == 0) cout << '*';
	else if (muls.size() == 0 && adds.size() == 0) {
		if (p == 0) cout << '*';
		else {
			h = (h - 1) / p + 1;
			long long rounds = (h - 1) / cnt;
			cout << rounds * n + h - rounds * cnt;
		}
	}
	else {
		long long inf = 1e9;
		int ans = 0;

		while (true) {
			long long cur = p;
			for (auto &x: adds) cur = min(cur + x, inf);
			for (auto &x: muls) cur = min(cur * x, inf);

			if (cur * cnt < h) {
				h -= cur * cnt;
				ans += n;
				p = cur;
			}
			else {
				int res = n;
				long long cur_add = p;

				for (int i = 0; i <= adds.size(); i ++) {
					if (i) cur_add = min(cur_add + adds[i - 1], inf);
					long long cur_mul = cur_add;

					for (int j = 0; j <= muls.size(); j ++) {
						if (j) cur_mul = min(cur_mul * muls[j - 1], inf);

						for (int k = 0; k <= cnt; k ++) {
							if (cur_mul * k >= h) {
								res = min(res, i + j + k);
							}
						}
					}
				}

				ans += res;
				break;
			}
		}
		cout << ans;
	}

	return 0;
}