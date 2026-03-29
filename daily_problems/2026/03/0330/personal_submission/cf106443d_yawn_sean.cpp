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

	int M = 5e5 + 5;

	vector<int> dp(M, 0), dp_acc(M, 0);

	for (int i = 1; i < M; i ++) {
		if (dp_acc[i] - dp_acc[i / 2] != i - i / 2) dp[i] = 1;
		dp_acc[i + 1] = dp_acc[i] + dp[i]; 
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;
		cout << (dp[n] ? "mastermei\n" : "the greatest\n");
	}

	return 0;
}