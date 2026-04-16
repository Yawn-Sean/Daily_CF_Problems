#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

vector<int> prep(const vector<int> &p) {
    vector<int> pi(p.size(), 0);
    int j = 0;
    for (int i = 1; i < (int)p.size(); i++) {
        while (j != 0 && p[j] != p[i])
            j = pi[j - 1];
        if (p[j] == p[i])
            j ++;
        pi[i] = j;
    }
    return pi;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	cin >> n >> m;

	vector<int> nums(m);
	for (auto &x: nums) cin >> x;

	for (int i = 1; i <= n; i ++) {
		vector<int> vals(m);
		for (auto &x: vals) cin >> x;
		vals.emplace_back(-1);
		vals.insert(vals.end(), nums.begin(), nums.end());
		vals.insert(vals.end(), nums.begin(), nums.end());

		auto kmp = prep(vals);
		for (auto &v: kmp) if (v == m) return cout << i, 0;
	}

	cout << -1;

	return 0;
}