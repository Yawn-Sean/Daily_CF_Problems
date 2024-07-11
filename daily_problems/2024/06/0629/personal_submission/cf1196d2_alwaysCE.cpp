#include <bits/stdc++.h>

using i64 = long long;

i64 inf = 100000007;
i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::map<char,int> mp;
	mp['R'] = 0; mp['G'] = 1; mp['B'] = 2;

	int q;
	std::cin >> q;
	while (q--) {
		int n, k;
		std::cin >> n >> k;
		std::string s;
		std::cin >> s;
		
		if (k == 1) {
			std::cout << 0 << '\n';
		} else if (k == 2) {
			if (s.find("RG") != std::string::npos or s.find("GB") != std::string::npos or s.find("BR") != std::string::npos) {
				std::cout << 0 << '\n';
			} else {
				std::cout << 1 << '\n';
			}
		} else {
			std::vector<std::vector<int>> pre(3, std::vector<int>(3));
			
			for (int i = 0; i < k; i++) {
				pre[i % 3][mp[s[i]] ]++;
			}
			
			std::function<int()> check = [&]()->int {	
				// R0 G1 B2
				// G0 B1 R2
				// B0 R1 G2
				int t1 = pre[0][0] + pre[1][1] + pre[2][2];
				int t2 = pre[0][1] + pre[1][2] + pre[2][0];
				int t3 = pre[0][2] + pre[1][0] + pre[2][1];
				return std::min(k - t1, std::min(k - t2, k - t3));
			};
			
			std::function<void()> change = [&]()->void {	
				std::vector<std::vector<int>> tmp(3, std::vector<int>(3));
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						tmp[(i + 2) % 3][j] += pre[i][j];
					}
				}
				for (int i = 0; i < 3; i++) {
					for (int j = 0; j < 3; j++) {
						pre[i][j] = tmp[i][j];
					}
				}
			};
			
			int ans = check();
			for (int i = k; i < n; i++) {
				--pre[0][mp[s[i - k]] ];
				change();
				++pre[(k-1) % 3][mp[s[i]] ];
				ans = std::min(ans, check());
			}
			
			std::cout << ans << '\n';
		}
	}
	return 0;
}
