#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

long long quickPow(long long base, long long power, long long mod) {
    if (power == 0) return 1 % mod;
    long long cur = quickPow(base, power / 2, mod);
    return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, op, s2;
	cin >> s1 >> op >> s2;

	int mod1 = 1e9 + 7, mod2 = mod1 - 1;

	int v1 = 0, v2 = 0;

	for (auto &c: s1)
		v1 = (10ll * v1 + c - '0') % mod1;

	for (auto &c: s2)
		v2 = (10ll * v2 + c - '0') % (op[0] == '^' ? mod2 : mod1);

	if (op == "+") cout << (v1 + v2) % mod1;
	else if (op == "-") cout << (v1 - v2 + mod1) % mod1;
	else if (op == "*") cout << 1ll * v1 * v2 % mod1;
	else cout << quickPow(v1, v2, mod1);

	return 0;
}