#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

const int N = 5;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	if (n >= 34) {
		cout << 0 << endl;
	} else {
		vector<vector<int>> coor(N, vector<int>(n));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < N; j ++) {
				cin >> coor[j][i];
			}
		}
		vector<int> ans;
		for (int i = 0; i < n; i ++) {
			bool flag = true;
			for (int j = 0; j < n && flag; j ++) {
				for (int k = 0; k < j && flag; k ++) {
					int res = 0;
					for (int d = 0; d < N; d ++) {
						res += (coor[d][k] - coor[d][i]) * (coor[d][j] - coor[d][i]);
					}
					if (res > 0) flag = false;
				}
			}
			if (flag) ans.emplace_back(i + 1);
		}
		cout << ans.size() << endl;
		for (auto x : ans) cout << x << endl;
	}
	return 0;
}
