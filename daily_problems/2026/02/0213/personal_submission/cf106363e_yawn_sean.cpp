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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> nums(n), pos(n);
	for (int i = 0; i < n; i ++) {
		int v;
		cin >> v;
		nums[i] = v;
		pos[v] = i;
	}

	int l = pos[0], r = pos[0];

	vector<long long> diff_0(n + 1, 0), diff_1(n + 1, 0);

	for (int i = 0; i < n; i ++) {
		l = min(l, pos[i]);
		r = max(r, pos[i]);

		diff_0[l] += 1ll * (n - r) * (l + 1);
		diff_0[r + 1] -= 1ll * (n - r) * (l + 1);

		diff_1[0] += n - r;
		diff_1[l] -= n - r;
		diff_0[0] += n - r;
		diff_0[l] -= n - r;

		diff_1[r + 1] -= l + 1;
		diff_1[n] += l + 1;
		diff_0[r + 1] += 1ll * (l + 1) * n;
		diff_0[n] -= 1ll * (l + 1) * n;
	}

	for (int i = 0; i < n; i ++) {
		diff_1[i + 1] += diff_1[i];
		diff_0[i + 1] += diff_0[i];
		cout << diff_1[i] * i + diff_0[i] << '\n';
	}

	return 0;
}