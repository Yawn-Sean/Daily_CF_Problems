#include <bits/stdc++.h>
using i64 = long long;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::string s;
	std::cin >> s;
	
	int ans = 0;
	while (true) {
		int idx = -1;
		for (int i = 0; i < n; i++) {
			if ( ((i > 0 and (s[i] - s[i - 1] == 1)) or (i + 1 < n and s[i] - s[i + 1] == 1) ) and (idx == -1 or s[i] > s[idx]) ) {
				idx = i;
			}
		}
		if (idx == -1) {
			break;
		}
		s = s.substr(0, idx) + s.substr(idx + 1);
		n--; ans++;
	}
	std::cout << ans << '\n';
	return 0;
}
