#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		string s, c;
		cin >> s >> c;
		
		vector<int> v1, v2;
		for (auto&ch: s) { v1.push_back(ch - 'A'); }
		for (auto&ch: c) { v2.push_back(ch - 'A'); }

		int n = s.size();
		vector<int> mn(n + 1, 27);
		for (int i = n - 1; i >= 0; i--) {
			mn[i] = min(mn[i + 1], v1[i]);
		}
		
		for (int i = 0 ; i < n; i++) {
			if (v1[i] != mn[i]) {
				int idx = -1;
				for (int j = i + 1; j < n; j++) {
					if (v1[j] == mn[i]) {
						idx = j;
					}
				}
				
				swap(v1[i], v1[idx]);
				break;
			}
		}
		
		string ans;
		for (auto& x: v1) {
			ans += (char)('A' + x);
		}
		cout << (ans < c ? ans : "---") << '\n';
	}
	return 0;
}
