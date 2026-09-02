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

	string s;
	cin >> s;

	vector<int> vals;
	for (auto &c: s) vals.emplace_back(c - '0');

	reverse(vals.begin(), vals.end());

	int carry = 0;

	for (int i = 0; i < vals.size(); i ++) {
		vals[i] = vals[i] * 9 + carry;
		carry = vals[i] / 10;
		vals[i] %= 10;
	}

	vals.emplace_back(carry);
	vals.emplace_back(0);

	int ans = 0;

	for (int i = vals.size() - 1; i >= 0; i --) {
		while (vals[i]) {
			ans ++;
			vals[0] ++;

			for (int j = 0; j < vals.size(); j ++) {
				if (vals[j] > 9) vals[j] -= 10, vals[j + 1] ++;
				else break;
			}

			if (vals[i + 1]) vals[i + 1] --;
			else vals[i] --;
		}
	}

	cout << ans;

	return 0;
}