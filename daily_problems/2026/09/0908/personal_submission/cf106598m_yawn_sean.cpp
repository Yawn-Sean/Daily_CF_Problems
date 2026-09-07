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

	string s, t;
	int p, q;
	cin >> s >> t >> p >> q;

	if (!p || !q) cout << '=';
	else {
		string s1 = s + t;
		string s2 = t + s;

		if (s1 < s2) cout << '<';
		else if (s1 > s2) cout << '>';
		else cout << '=';
	}

	return 0;
}