#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int m;
	std::cin >> m;
	std::string s;
	std::cin >> s;
	
	int n = (int)s.size();
	// 枚举最大字符
	for (int i = 0; i < 26; i++) {
		int cur = -1;
		bool ok = true;
		for (int j = 0; j < n; j++) {
			if ((s[j] - 'a') <= i) {
				cur = j;
			} else if (j - cur >= m) {
				ok = false;
			}
		}
		if (ok) {
			std::vector<int> cnt(26);
			int cur = -1, pre = -1;
			
			for (int j = 0; j < n; j++) {
				int x = s[j] - 'a';
				if (x < i) {
					cur = j;
					cnt[x]++;
				} else if (x == i) {
					pre = j;
				}
				// 选择最靠后的i
				if (j - cur == m) {
					cnt[i]++;
					cur = pre;
				}
			}
			
			for (int c = 0; c < 26; c++) {
				for (int j = 0; j < cnt[c]; j++) {
					std::cout << (char)('a' + c);
				}
			}
			return 0;
		}
	}
	return 0;
}
