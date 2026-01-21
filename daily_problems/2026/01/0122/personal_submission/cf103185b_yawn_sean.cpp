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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	vector<int> inc_length(n, 1), dec_length(n, 1);
	int pos;

	pos = -1;
	for (int i = n - 1; i >= 0; i --) {
		if (nums[i] > 0) {
			if (pos != -1) {
				if (nums[i] > nums[pos]) inc_length[i] = pos - i;
				else inc_length[i] = inc_length[i] = inc_length[i + 1] + 1;
			}
			pos = i;
		}
		else if (i != n - 1) inc_length[i] = inc_length[i + 1] + 1;
	}

	pos = -1;
	for (int i = 0; i < n; i ++) {
		if (nums[i] > 0) {
			if (pos != -1) {
				if (nums[i] > nums[pos]) dec_length[i] = i - pos;
				else dec_length[i] = dec_length[i] = dec_length[i - 1] + 1;
			}
			pos = i;
		}
		else if (i) dec_length[i] = dec_length[i - 1] + 1;
	}

	bool total_flg = false;
	for (int i = 3; i <= n; i ++) {
		bool flg = true;
		for (int j = 0; j < n; j += i) {
			int l = j, r = min(j + i - 1, n - 1);
			if (inc_length[l] + dec_length[r] < r - l + 2 || r - l + 1 < 3 || inc_length[l] < 2 || dec_length[r] < 2) flg = false;
		}
		total_flg |= flg;
	}

	cout << (total_flg ? "Y" : "N");

	return 0;
}