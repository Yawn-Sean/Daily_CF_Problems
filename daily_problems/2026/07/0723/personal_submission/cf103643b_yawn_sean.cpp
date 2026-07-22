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

	int t;
	cin >> t;

	while (t --) {
		int a, b;
		cin >> a >> b;

		set<pair<int, int>> st;

		st.insert({a + b, 1});
		st.insert({a - b, 1});
		st.insert({b - a, 1});

		int g = gcd(a, b);
		st.insert({a * b, 1});
		st.insert({a / g, b / g});
		st.insert({b / g, a / g});

		cout << st.size() << '\n';
	}

	return 0;
}