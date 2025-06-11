#include <cstdint>
#include <iostream>
#include <set>
#include <utility>

#define KV(x) #x << " -> " << x

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int64_t X;
	std::cin >> X;

	std::set<std::pair<int64_t, int64_t>> ans;
	for (int64_t n = 1; n * n * n * 2 <= X * 6; n++) {
		int64_t q = X * 6 + n * n * n - n;
		int64_t p = n * (n + 1) * 3;
		if (q % p != 0) {
			continue;
		}

		int64_t m = q / p;

		if (ans.count(std::make_pair(n, m))) break;
		ans.insert(std::make_pair(n, m));
		ans.insert(std::make_pair(m, n));
	}

	std::cout << ans.size() << '\n';
	for (auto &[p, q] : ans) {
		std::cout << p << ' ' << q << '\n';
	}
}
