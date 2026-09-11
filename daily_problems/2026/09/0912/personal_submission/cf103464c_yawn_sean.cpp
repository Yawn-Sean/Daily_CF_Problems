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
	string s;
	cin >> n >> s;

	vector<int> manacher(n - 1, 0);
	int chosen_idx = 0;

	for (int i = 0; i < n - 1; i ++) {
		if (chosen_idx + manacher[chosen_idx] >= i && 2 * chosen_idx >= i) {
			manacher[i] = min(manacher[2 * chosen_idx - i], chosen_idx + manacher[chosen_idx] - i);
		}

		int l = i - manacher[i] + 1, r = i + manacher[i];

		while (l && r + 1 < n && s[l - 1] != s[r + 1]) {
			l --, r ++;
			manacher[i] ++;
		}

		if (i + manacher[i] > chosen_idx + manacher[chosen_idx]) {
			chosen_idx = i;
		}
	}

	cout << *max_element(manacher.begin(), manacher.end()) * 2;

	return 0;
}