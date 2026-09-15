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
		int n;
		cin >> n;

		vector<int> v1(n), v2(n);
		for (auto &x: v1) cin >> x;
		for (auto &x: v2) cin >> x;

		vector<int> p1(n), p2(n);
		iota(p1.begin(), p1.end(), 0);
		iota(p2.begin(), p2.end(), 0);
		sort(p1.begin(), p1.end(), [&] (int i, int j) {return v1[i] < v1[j];});
		sort(p2.begin(), p2.end(), [&] (int i, int j) {return v2[i] < v2[j];});

		vector<int> p(n);
		for (int i = 0; i < n; i ++) p[p1[i]] = p2[n - 1 - i];

		for (int i = 0; i < n; i ++) cout << p[i] + 1 << " \n"[i == n - 1];
	}

	return 0;
}