#include <bits/stdc++.h>

// #define DEBUG

using i64 = long long;
using u32 = unsigned int;
using u64 = unsigned long long;

constexpr int inf32 = 1E9 + 7;
constexpr i64 inf64 = 1E18 + 7;
constexpr int P = 1E9 + 7;

void solve(){
	int n;
	std::cin >> n;

	std::vector<std::string> nums(n);
	std::map<std::string, int> mp;
	for (int i = 0; i < n; ++ i) {
		std::cin >> nums[i];
		for (int j = 0; j < 9; ++ j) {
			std::string sub;
			for (int k = j; k < 9; ++ k) {
				sub += nums[i][k];
				auto it = mp.find(sub);
				if (it == mp.end())
					mp[sub] = i;
				else {
					if (it -> second == i) continue;
					it -> second = -1;
				}
			}
		}
	}

	for (int i = 0; i < n; ++ i) {
		std::string ans = std::string(10, '0');
		for (int j = 0; j < 9; ++ j) {
			std::string sub;
			for (int k = j; k < 9; ++ k) {
				sub += nums[i][k];
				if (mp[sub] == i && sub.size() < ans.size()) {
					ans = sub;
				}

			}
		}
		std::cout << ans << '\n';
	}
}

auto FIO = []{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main() {
	#ifdef DEBUG
		freopen("in.txt", 'r', stdin);
		freopen("out.txt", 'w', stdout);
	#endif
	int t = 1;
	// std::cin >> t;
	while(t --)
		solve();
	return 0;
}