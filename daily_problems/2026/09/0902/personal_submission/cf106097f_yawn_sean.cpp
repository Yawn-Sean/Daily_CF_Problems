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

	auto query = [&] (int x) -> char {
		cout << x << endl;
		char c; cin >> c;
		return c;
	};

	auto answer = [&] (int x1, int x2) -> void {
		cout << "! " << x1 << ' ' << x2 << endl;
	};

	auto search = [&] (int l, int r) -> int {
		while (l <= r) {
			int mid = (l + r) / 2;
			auto res = query(mid);

			if (res == '=') return mid;
			if (res == '>') l = mid + 1;
			else r = mid - 1;
		}

		return -1;
	};

	int n;
	cin >> n;

	auto v1 = search(1, n);
	auto v2 = max(search(1, v1 - 1), search(v1 + 1, n));

	if (v1 > v2) swap(v1, v2);
	answer(v1, v2);

	return 0;
}