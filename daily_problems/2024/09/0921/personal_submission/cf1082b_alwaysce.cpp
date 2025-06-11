#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	string s;
	cin >> s;
	
	map<char,int> cnt;
	int l = 0, ans = 0, cnt_g = 0;
	for (int r = 0; r < n; r++) {
		cnt[s[r]]++;
		if (s[r] == 'G') { cnt_g++; }
		while (l < r and cnt['S'] > 1) {
			cnt[s[l]]--;
			l++;
		}
		ans = max(ans, r - l + 1);
	}
	
	ans = min(ans, cnt_g);
	cout << ans << '\n';
	return 0;
}
