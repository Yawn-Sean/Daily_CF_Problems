#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<int> v1(n + 1, 0), v2(n + 1, 0);

	for (int i = 1; i <= n; i ++) cin >> v1[i];
	for (int i = 1; i <= n; i ++) cin >> v2[i];

	int w1 = v1[n], v2[n];

	for (int i = n - 1; i >= 0; i --) {
		int nw1 = max(w1, min(v1[i], w2)), nw2 = min(w2, max(v2[i], w1));
		w1 = nw1, w2 = nw2;
	}

	cout << w1;

	return 0;
}