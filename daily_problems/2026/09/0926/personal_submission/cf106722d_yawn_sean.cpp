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

	int cycle_size = n;

	for (int i = 1; i <= n; i ++) {
		while (cycle_size > 1) {
			cout << "? " << i << ' ' << cycle_size - 1 << endl;
			string x; cin >> x;
			if (x == "Yes") cycle_size --;
			else break;
		}
	}

	vector<int> ans;

	for (int i = 1; i <= n; i ++) {
		cout << "? " << i << ' ' << cycle_size << endl;
		string x; cin >> x;
		if (x == "Yes") ans.emplace_back(i);
	}

	cout << "! " << ans.size();
	for (auto &v: ans) cout << ' ' << v;

	return 0;
}