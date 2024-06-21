#include <bits/stdc++.h>

using i64 = long long;

i64 mod = 1000000007;

i64 pow(i64 base, i64 exp) {
	i64 res = 1;
	while (exp) {
		if (exp & 1) {
			res = res * base % mod;
		}
		base = base * base % mod;
		exp >>= 1;
	}
	return res;
}

i64 inv(i64 x) {
	return pow(x, mod - 2) % mod;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	i64 A, B, n, x;
	std::cin >> A >> B >> n >> x;
	
	// A^n x + B(1 + A + ... + A^(n - 1))
	// B(A^n - 1) * inv(A - 1) + A^n x
	if (A == 1) {
		std::cout << (x + (B * (n % mod) % mod) + mod) % mod << '\n';
	} else {
		i64 pa = pow(A, n);
		i64 r1 = (pa * x) % mod;
		i64 r2 = B * (pa - 1) % mod;
		r2 *= inv(A - 1) % mod;
		std::cout << (r1 + r2 + mod) % mod << '\n'; 
	}
	return 0;	
}
