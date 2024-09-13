#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<vector<int>> a(m, vector<int>(n));
	vector<vector<pair<int, int>>> delta(n - 1, vector<pair<int, int>>(m));
	vector<int> tot(n);
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> a[i][j];
			tot[j] += a[i][j];
		}
		for (int j = 0; j < n - 1; j ++) {
			delta[j][i].first = a[i][n - 1] - a[i][j];
			delta[j][i].second = i;
		}
	}
	for (int i = 0; i < n - 1; i ++){
		if (tot[n - 1] <= tot[i]){
			cout << "0\n\n" << endl;
			return 0;
		}
	}
	int mn = m - 1;
	vector<int> ans(n);
	iota(ans.begin(), ans.end(), 0);
	for (int i = 0; i < n - 1; i ++){
		sort(delta[i].begin(), delta[i].end(), greater<>());
		int tot_delta = tot[n - 1] - tot[i];
		vector<int> tmp;
		for (int j = 0; j < min(mn + 1, m); j ++){
			tmp.push_back(delta[i][j].second);
			tot_delta -= delta[i][j].first;
			if (tot_delta <= 0){
				if (mn > j){
					mn = j;
					ans = tmp;
				}
				break;
			}
		}
	}
	cout << mn + 1 << endl;
	for (int i = 0; i <= mn; i ++){
		cout << ans[i] + 1 << " \n"[i == mn];
	}
	return 0;
}
