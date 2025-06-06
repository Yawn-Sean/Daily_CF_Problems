#include<bits/stdc++.h>
using namespace std;
const int N = 1e3 + 5;
char mp[N][N];
int vis[N][N], idx;
int cnt[N * N];
int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
int dfs(int x, int y) {
	vis[x][y] = idx;
	int res = 1;
	for (int i = 0; i < 4; i++) {
		int xx = x + dx[i], yy = y + dy[i];
		if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == '.' && !vis[xx][yy]) {
			res += dfs(xx, yy);
            res%=10;
		}
	}
	return res;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> mp[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (mp[i][j] == '.' && !vis[i][j]) {
				idx++;
				cnt[idx] = dfs(i, j);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			// cout<<vis[i][j];
			if (mp[i][j] == '.' ) {
				cout << '.';
			} else {
				int tmp[5] = {0};
				int res = 1;
				for (int k = 0; k < 4; k++) {
					int xx = i + dx[k], yy = j + dy[k];
					if (xx >= 1 && xx <= n && yy >= 1 && yy <= m && mp[xx][yy] == '.' ) {
						bool fg = 1;
						for (int ii = 0; ii < k; ii++) {
							if (tmp[ii] == vis[xx][yy]) {
								fg = 0;
								break;
							}
						}
						if (fg) {
							tmp[k] = vis[xx][yy];
							res += cnt[vis[xx][yy]];
                            res%=10;
						}
					}

				}
				cout << res;
			}
		}
		cout << '\n';
	}
	// for(int i=1;i<=idx;i++){
	//     cout<<"i:"<<i<<" cnt_i:"<<cnt[i]<<endl;
	// }
	return 0;
}
