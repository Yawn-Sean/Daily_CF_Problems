#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, b;
	cin >> n >> b;

	vector<long long> nums(n);
	for (auto &x: nums) cin >> x;

	int k = 0;
	vector<long long> base(b, 0);
	vector<long long> base_msk(b, 0), msks;

	for (auto &x: nums) {
		bool flg = true;
		long long msk = 0;

		for (int i = b - 1; i >= 0; i --) {
			if (x >> i & 1) {
				if (!base[i]) {
					base[i] = x;
					base_msk[i] = (1ll << k) ^ msk;
					flg = false;
					k ++;
					break;
				}
				else {
					x ^= base[i];
					msk ^= base_msk[i];
				}
			}
		}

		if (flg) msks.emplace_back(msk);
	}

	int c0 = -1, c1 = -1, c2 = -1;

	for (int i = 0; i < k; i ++) {
		long long total_msk = (1ll << i) - 1;
		long long total_nmsk = (1ll << i) - 1;

		int c = 0;

		for (auto &v: msks) {
			if (v >> i & 1) c ++, total_msk &= v;
			else total_nmsk &= ~v;
		}

		int same = __builtin_popcountll(total_msk & total_nmsk) + 1;
		if (c == 0) c0 = max(c0, same);
		else if (c == 1) c1 = max(c1, same);
		else c2 = max(c2, same);
	}

	for (int extra = 0; extra < 8; extra ++) {
		if ((1 << extra) - extra - 1 >= c0 && (1 << extra) - 1 >= c1 && (1 << extra) >= c2) {
			cout << extra;
			break;
		}
	}

	return 0;
}