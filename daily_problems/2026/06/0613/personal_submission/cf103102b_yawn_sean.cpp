#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s;
	cin >> s;

	int c1 = 0, rev = 0;

	for (auto &c: s) {
		if (c == '1') c1 = (c1 + 1) % 3;
		else rev = (rev + c1) % 3;
	}

	cout << (rev ? "Alice" : "Bob");

	return 0;
}