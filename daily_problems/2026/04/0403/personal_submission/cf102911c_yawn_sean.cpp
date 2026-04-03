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

	int M = 5e6 + 5;

	vector<int> pr(M);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i < M; i ++) {
		if (pr[i] == i) {
			for (int j = i; j < M; j += i) {
				pr[j] = i;
			}
		}
	}

	vector<int> sg_vis(M, 0), sg(M, 0);

	for (int i = 2; i < M; i ++) {
		int cur = i;
		while (cur > 1) {
			sg_vis[i] |= sg_vis[i / pr[cur]];
			sg_vis[i] |= 1 << sg[i / pr[cur]];
			cur /= pr[cur];
		}

		int x = ~sg_vis[i];
		x &= -x;
		sg[i] = __builtin_ctz(x);
	}

	int m, n, x, y;
	cin >> m >> n >> x >> y;

	vector<int> c1(30, 0), c2(30, 0);

	for (int i = 0; i <= x; i ++) c1[sg[m - i]] ++;
	for (int i = 0; i <= y; i ++) c2[sg[n - i]] ++;

	long long ans = 1ll * (x + 1) * (y + 1);

	for (int i = 0; i < 30; i ++)
		ans -= 1ll * c1[i] * c2[i];

	cout << ans;

	return 0;
}