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
	cin >> n;

	vector<int> nums(n);
	int g = 0;
	for (auto &x: nums) {
		cin >> x;
		g = gcd(x, g);
	}

	for (auto &x: nums)
		x /= g;
	
	int M = *max_element(nums.begin(), nums.end());
	vector<int> pr(M + 1);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= M; j += i) {
				pr[j] = i;
			}
		}
	}

	vector<int> vis(M + 1, 0);

	for (auto &x: nums) {
		while (x > 1) {
			int p = pr[x];
			if (vis[p]) return cout << "NO", 0;
			vis[p] = 1;
			while (x % p == 0) x /= p;
		}
	}

	cout << "YES";

	return 0;
}