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

	vector<int> p(n), q(n);
	for (auto &x: p) cin >> x;
	for (auto &x: q) cin >> x;

	auto solve = [&] (vector<int> &nums) -> long long {
		int mi = *min_element(nums.begin(), nums.end());
		int ma = *max_element(nums.begin(), nums.end());

		vector<int> cnt(ma - mi + 1);
		for (auto &x: nums) cnt[x - mi] ++;

		vector<int> tmp;
		for (int i = 0; i <= ma - mi; i ++)
			while (cnt[i] --) tmp.emplace_back(i);
		
		long long ans = 0;
		for (int i = 0; i < n; i ++)
			ans += 1ll * (2 * i - n + 1) * tmp[i];
		return ans;
	};

	long long ans = (solve(p) + solve(q)) * 2;

	vector<int> tmp(n);

	for (int i = 0; i < n; i ++) tmp[i] = p[i] - q[i];
	ans -= solve(tmp);

	for (int i = 0; i < n; i ++) tmp[i] = p[i] + q[i];
	ans -= solve(tmp);

	cout << ans;

    return 0;
}