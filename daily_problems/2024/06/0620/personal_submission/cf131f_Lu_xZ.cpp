#include<bits/stdc++.h>
#define eb emplace_back
#define ep emplace
using namespace std;

using ll = long long;

int n, m, lim, s[550][550];
ll ans;
char g[550][550];

int get(int x1, int y1, int x2, int y2) {
	++ x1, ++ y1;
	-- x2, -- y2;
	return max(0, s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]);
} 

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> n >> m >> lim;
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			cin >> g[i][j];
			g[i][j] -= '0';
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			if(g[i][j] && g[i - 1][j] && g[i][j - 1] && g[i + 1][j] && g[i][j + 1]) 
				s[i][j] = 1;
			s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
		}
	}
	for(int i = 1; i <= n; ++ i) {
		for(int j = 1; j <= m; ++ j) {
			for(int k = i; k <= n; ++ k) {
				if(get(i, j, k, m) < lim) continue;
				int l = j, r = m;
				while(l < r) {
					int mid = l + r >> 1;
					if(get(i, j, k, mid) >= lim) r = mid;
					else l = mid + 1;
				}
				ans += m - l + 1;
			} 
		}
	}
	cout << ans;
	return 0;
}
