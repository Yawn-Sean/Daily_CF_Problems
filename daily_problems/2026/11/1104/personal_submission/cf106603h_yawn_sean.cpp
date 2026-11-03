#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

long long quickPow(long long base, long long power, long long mod) {
	if (power == 0) return 1 % mod;
	long long cur = quickPow(base, power / 2, mod);
	return power & 1 ? base * cur % mod * cur % mod : cur * cur % mod; 
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, mod = 998244353;
	cin >> n;

	n -= 2;
	if (n == 1) cout << 1;
	else if (n % 3 == 0) cout << quickPow(3, n / 3, mod);
	else if (n % 3 == 1) cout << 4 * quickPow(3, n / 3 - 1, mod) % mod;
	else cout << 2 * quickPow(3, n / 3, mod) % mod;

	return 0;
}