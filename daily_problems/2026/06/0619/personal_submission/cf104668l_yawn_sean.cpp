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

	int n, a, b;
	cin >> n >> a >> b;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;

	int ma1 = 0, ma2 = 0;

	for (auto &x: nums) {
		if (x > ma1) swap(ma1, ma2), ma1 = x;
		else ma2 = max(ma2, x);
	}

	if (a == b) {
		int val = 0;
		for (auto &v: nums) val ^= v % (a + 1);
		cout << (val ? "Petyr" : "Varys");
	}
	else if (a > b) {
		if (ma1 > b) cout << "Petyr";
		else {
			int val = 0;
			for (auto &v: nums) val ^= v % (b + 1);
			cout << (val ? "Petyr" : "Varys");
		}
	}
	else {
		if (ma2 > a) cout << "Varys";
		else {
			int val = 0;
			for (auto &v: nums) val ^= v % (a + 1);
			
			if (ma1 <= a) cout << (val ? "Petyr" : "Varys");
			else {
				int target = (ma1 % (a + 1)) ^ val;
				cout << (target <= a && ma1 - target <= a ? "Petyr" : "Varys");
			}
		}
	}

	return 0;
}