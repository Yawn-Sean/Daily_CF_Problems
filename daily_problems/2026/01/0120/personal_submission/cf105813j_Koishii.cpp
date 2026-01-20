#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 200005;
int inv[N];

void init() {
	inv[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = (mod - 1LL * mod / i) * inv[mod % i] % mod;
	}
}

void soviet() {
	int n, k; std::cin >> n >> k;

	long long sum = 0;
	for (int i = 0; i < n; i++) {
		int x; std::cin >> x;
		sum = (sum + x) % mod;
	}
	std::cout << sum * inv[n] % mod << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	init();
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
