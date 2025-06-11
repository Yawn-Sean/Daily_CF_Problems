#include<bits/stdc++.h>
#define ep emplace
using namespace std;


int m, cnt[155][155];

int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> cnt[76][76] >> m;
	int flag = 1;
	while(flag) {
		flag = 0;
		for(int i = 1; i <= 151; ++ i) {
			for(int j = 1; j <= 151; ++ j) {
				if(cnt[i][j] >= 4) {
					flag = 1;
					int add = cnt[i][j] / 4;
					cnt[i][j] %= 4;
					for(int k = 0; k < 4; ++ k) {
						int x = i + dx[k], y = j + dy[k];
						cnt[x][y] += add;
					}
				}
			}
		}
	}
	while(m --) {
		int x, y;
		cin >> x >> y;
		
		if(abs(x) >= 75 || abs(y) >= 75) {
			cout << 0 << '\n';
		}
		else {
			cout << cnt[x + 76][y + 76] << '\n';
		}
	}
	return 0;
}
