#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int a, b, n;
		cin >> a >> b >> n;
		if (n > a + 2ll * (2 * b - 1)) cout << "Bob\n";
		else if (n <= a + 2ll * (b - 1)) cout << "Alice\n";
		else if (n < 3ll * a) cout << "Bob\n";
		else cout << "Alice\n";
	}

	return 0;
}