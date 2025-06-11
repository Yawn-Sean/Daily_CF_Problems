#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, q, c;
	const int N = 101;
	cin >> n >> q >> c;
	vector<vector<vector<int>>> stars(N, vector<vector<int>>(N, vector<int>(c + 1)));
	int x, y, s;
	for (int i = 0; i < n; i ++) {
		cin >> x >> y >> s;
		stars[x][y][s] ++;
	}
	for (int i = 1; i < N; i ++) {
		for (int j = 1; j < N; j ++) {
			for (int k = 0; k <= c; k ++) {
				stars[i][j][k] += stars[i - 1][j][k] + stars[i][j - 1][k] - stars[i - 1][j - 1][k];
			}
		}
	}
	int t, x1, y1, x2, y2;
	while (q -- ) {
		cin >> t >> x1 >> y1 >> x2 >> y2;
		int ans = 0;
		for (int i = 0; i <= c; i ++) {
			ans += (stars[x2][y2][i] - stars[x2][y1 - 1][i] - stars[x1 - 1][y2][i] + stars[x1 - 1][y1 - 1][i]) * ((i + t) % (c + 1));
		}
		cout << ans << endl;
	}
	return 0;
}
