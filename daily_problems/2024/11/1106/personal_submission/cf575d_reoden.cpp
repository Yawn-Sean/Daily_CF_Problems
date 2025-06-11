#include <bits/stdc++.h>
int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int N = 2000;
	std::cout << N << '\n';
	for (int i = 1; i <= N / 2; i++) {
		std::cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';
	}
	for (int i = N / 2; i >= 1; i--) {
		std::cout << i << ' ' << 1 << ' ' << i << ' ' << 2 << '\n';
	}
}
