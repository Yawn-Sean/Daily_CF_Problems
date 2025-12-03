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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> acc(n + 1);
		for (int i = 1; i <= n; i ++) {
			cin >> acc[i];
			acc[i] += acc[i - 1];
		}

		long long ans = 0;
		vector<int> stk = {n + 1};
		vector<long long> stk_acc = {0};

		for (int i = n; i >= 0; i --) {
			while (stk.back() != n + 1 && acc[i] > acc[stk.back()]) {
				stk_acc.pop_back();
				stk.pop_back();
			}

			stk_acc.emplace_back(stk_acc.back() + 1ll * (stk.back() - i) * acc[i]);
			stk.emplace_back(i);

			ans += stk_acc.back() - 1ll * (n + 1 - i) * acc[i];
		}

		cout << ans << '\n';
	}

	return 0;
}