#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		int r, c, k;
		std::cin >> r >> c >> k;
		
		std::vector<std::string> grid(r);
		for (auto &s : grid) std::cin >> s;

		auto gao = [&](int index) -> char {
			if (index < 10) {
				return static_cast<char>('0' + index);
			} else if (index < 10+26) {
				return static_cast<char>('A' + index - 10);
			}

			return static_cast<char>('a' + index - 10 - 26);
		};

		int idx = 0;
		int cnt = 0;
		int cur = 0;
		for (auto &s : grid) for (auto &ch : s) cur += (ch == 'R');
		
		int num = cur / k;
		int need = cur % k;
		bool rev = false;
		for (auto &s : grid) {
			if (rev) std::reverse(s.begin(), s.end());
			for (auto &ch : s) {
				cnt += (ch == 'R');
				ch = gao(idx);
				if (cnt == num + (need > 0)) {
					idx = std::min(idx+1, k-1);
					need--;
					cnt = 0;
				}
			}
			if (rev) std::reverse(s.begin(), s.end());
			rev ^= 1;
		}

		// WARNING: odd row assigned may not connect with even row
		for (auto &s : grid) std::cout << s << '\n';
	}
}
