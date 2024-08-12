#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int k;
	std::cin >> k;
	
	auto solve = [&]() {
		int n;
		std::cin >> n;
		std::vector<char> s, t;
		
		for (int i = 0; i < n; i++) {
			char ch;
			std::cin >> ch;
			s.push_back(ch);
		}
		for (int i = 0; i < n; i++) {
			char ch;
			std::cin >> ch;
			t.push_back(ch);
		}
			
		std::vector<int> cnt(26);
		// std::vector<std::vector<int>> pos_s(26), pos_t(26);
		
		for (int i = 0; i < n; i++) {
			cnt[s[i]-'a']++;
			cnt[t[i]-'a']++;
		}
		
		for (int i = 0; i < 26; i++) {
			if (cnt[i] % 2) {
				std::cout << "No\n";
				return;
			}
		}
		
		std::cout << "Yes\n";
		std::vector<std::pair<int,int>> ops;
		for (int i = 0; i < n; i++) {
			if (s[i] != t[i]) {
				bool find = false;

				for (int j = i + 1; j < n; j++) {
					if (s[j] == s[i]) {
						std::swap(t[i], s[j]);
						ops.push_back({j + 1, i + 1});
						find = true;
						break;
					}
				}
				
				if (!find) {
					for (int j = i + 1; j < n; j++) {
						if (t[j] == s[i]) {
							std::swap(t[j], s[i + 1]);
							ops.push_back({i + 2, j + 1});

							std::swap(t[i], s[i + 1]);
							ops.push_back({i + 2, i + 1});

							find = true;
							break;
						}
					}
				}
			}
		}
		std::cout << ops.size() << '\n';
		for (auto& [x, y]: ops) {
			std::cout << x  << ' ' << y << '\n';
		}
	};
		
	while (k--) {
		solve();
	}
	return 0;
}
