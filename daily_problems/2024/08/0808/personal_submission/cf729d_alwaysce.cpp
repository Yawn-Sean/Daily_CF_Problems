#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, a, b, k;
	std::cin >> n >> a >> b >> k;
	
	std::string s;
	std::cin >> s;
	
	std::vector<int> ans;
	for (int i = 0; i < n; ) {
		if (s[i] == '0') {
			int j = i;
			int cnt = 0;
			while (j < n and s[j] == '0') {
				++cnt;
				if (cnt >= b) {
					ans.push_back(j);
					cnt = 0;
				}
				j++;
			}
			i = j;
		} else {
			i++;
		}
	}
	for (int i = 0; i < a - 1; i++) {
		ans.pop_back();
	}

	std::cout << ans.size() << '\n';
	for (auto& x: ans) { std::cout << x + 1 << ' '; }
	std::cout << '\n';
	return 0;
}
