#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;
const int N = 1000006;
long long inv[N], h[N];

void init(){
	inv[1] = h[1] = 1;
	for (int i = 2; i < N; i++) {
		inv[i] = mod - mod / i * inv[mod % i] % mod;
		h[i] = (h[i - 1] + inv[i]) % mod;
	}
}

void soviet() {
	int n; std::cin >> n;
	std::cout << h[n] << '\n' << inv[n] << '\n';
	std::cout << (h[n] + inv[n] - 1) % mod << '\n';
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
	init();
	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
