#include <iostream>
#include <map>
#include <vector>

int main() {
	std::cin.tie(nullptr)->sync_with_stdio(false);
	int T;
	std::cin >> T;
	while (T--) {
		int N;
		std::cin >> N;
		std::map<int, int> cnt{};

		std::pair<int64_t, int64_t> ans{};
		for (int i = 0; i < N; i++) {
			int x; std::cin >> x;
			cnt[x]++;
			if (cnt[x] >= 4) {
				ans = {x, x};
			}
		}
		
		std::vector<int> vc;
		for (auto &[v, c] : cnt) {
			if (c >= 2) vc.push_back(v);
		}

		for (int i = 1; i + 1 < static_cast<int>(vc.size()); i++) {
			{
				std::pair<int64_t, int64_t> cur = {vc[i-1], vc[i]};
				if ((cur.first + cur.second) * (cur.first + cur.second) * (ans.second * ans.first) <= (ans.first + ans.second) * (ans.second + ans.first) * (cur.first * cur.second)) {
					ans = cur;
				}
			}
			{
				std::pair<int64_t, int64_t> cur = {vc[i+1], vc[i]};
				if ((cur.first + cur.second) * (cur.first + cur.second) * (ans.second * ans.first) <= (ans.first + ans.second) * (ans.second + ans.first) * (cur.first * cur.second)) {
					ans = cur;
				}
			}
		}

		if (ans == std::pair<int64_t, int64_t>{0, 0}) {
			ans = {vc.front(), vc.back()};
		}

		std::cout << ans.first << ' ' << ans.first << ' ' << ans.second << ' ' << ans.second << '\n';
	}
}
