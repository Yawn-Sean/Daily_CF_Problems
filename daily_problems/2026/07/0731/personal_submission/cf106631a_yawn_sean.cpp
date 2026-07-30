#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int lcm_val, lcm_val_a, a, b;
		cout << "MUL " << 1 << endl;
		cin >> lcm_val;
		cout << "MUL " << lcm_val << endl;
		cin >> lcm_val_a;
		a = lcm_val_a / lcm_val;
		cout << "DIV " << lcm_val_a << endl;
		cin >> b;
		cout << "ANS " << a << ' ' << b << endl;
	}

	return 0;
}