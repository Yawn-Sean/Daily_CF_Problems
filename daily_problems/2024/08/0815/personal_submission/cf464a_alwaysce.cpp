#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	int n, p;
	std::cin >> n >> p;
	
	std::string s;
	std::cin >> s;
	
	for (int i = n - 1; i >= 0; i--) {
		int cur = s[i] - 'a';
		
		for (int j = cur + 1; j < p; j++) {
			bool ok = true;
			char ch = (char)('a' + j);
			
			for (int k = 1; k <= 2; k++) {
				if (i - k >= 0 and s[i - k] == ch) {
					ok = false;
				}
			}
			if (ok) {
				s[i] = ch;
				
				for (int idx = i + 1; idx < n; idx++) {
					for (int nc = 0; nc < p; nc++) {
						ok = true;
						char nch = (char)('a' + nc);
						
						for (int nj = 1; nj <= 2; nj++) {
							if (idx - nj >= 0 and s[idx - nj] == nch) {
								ok = false;
							}
						}
						if (ok) {
							s[idx] = nch;
							break;
						}
					}
				}
				
				std::cout << s << '\n';
				return 0;
			}
		}
	}
	std::cout << "NO\n";
	return 0;
}
