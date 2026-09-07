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

	long long a, b;
	cin >> a >> b;

	string aa = "A+=A", ab = "A+=B", ba = "B+=A", bb = "B+=B";
	vector<string> ops;

	while (a != b) {
		if (a % 2 == 0) a /= 2, ops.emplace_back(bb);
		else if (b % 2 == 0) b /= 2, ops.emplace_back(aa);
		else if (a > b) {
			a = (a + b) / 2;
			ops.emplace_back(ab);
			ops.emplace_back(bb);
		}
		else {
			b = (a + b) / 2;
			ops.emplace_back(ba);
			ops.emplace_back(aa);
		}
	}

	cout << ops.size() << '\n';
	for (auto &x: ops) cout << x << '\n';

	return 0;
}