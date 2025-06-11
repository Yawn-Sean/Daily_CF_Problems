#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 2e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	// x1 [...] x1 [...]
	string s;
	cin >> s;
	
	vector<int> vis(26, -1);
	for (int i = 0; i < 27; i++) {
		int ch = (s[i] - 'A');
		
		if (vis[ch] == -1) { vis[ch] = i;}
		else {
			if (vis[ch] == i - 1) {
				cout << "Impossible";
				return 0;
			}
			
			int dis = i - vis[ch] - 1;
			vector<string> ans(2, string(13, ' '));
			for (int j = 0; j < dis - dis / 2; j++) {
				ans[0][j] = s[i - (dis - dis / 2 - j)];
				ans[1][j] = s[vis[ch] + dis / 2 - j];
			}
			ans[1][dis / 2] = s[i];
			
			int sx = 1, sy = dis / 2;
			for (int j = vis[ch] - 1; j >= 0; j--) {
				sy += (sx > 0 ? 1 : -1);
				if (sy >= 13) {
					sx = 0;
					sy = 12;
				}
				ans[sx][sy] = s[j];
			}
			
			sx = 0, sy = dis - dis / 2 - 1;
			for (int j = i + 1; j < 27; j++) {
				sy += (sx > 0 ? -1: 1);
				if (sy >= 13) {
					sx = 1;
					sy = 12;
				}
				ans[sx][sy] = s[j];
			}
			
			cout << ans[0] << '\n' << ans[1];
		}
	}

	return 0;
}
