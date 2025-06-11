#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n, m;
	cin >> n >> m;
	vector<int> a(m);
	for (auto &x : a){
		cin >> x;
	}
	i64 tot = 0;
	vector<i64> delta(n + 1);
	vector<vector<int>> neibors(n + 1, vector<int>());
	for (int i = 1; i < m; i ++){
		int v = abs(a[i] - a[i - 1]);
		tot += v;
		if (a[i] != a[i - 1]){
			delta[a[i]] += v;
			delta[a[i - 1]] += v;
			neibors[a[i]].push_back(a[i - 1]);
			neibors[a[i - 1]].push_back(a[i]);
		}
	}
	i64 mx = 0;
	for (int i = 1; i <= n; i ++){
		if (!neibors[i].empty()){
			sort(neibors[i].begin(), neibors[i].end());
			int median = neibors[i][(int)neibors[i].size() / 2];

			i64 tmp = 0;
			for (auto &x : neibors[i]){
				tmp += abs(x - median);
			}
			mx = max(mx, delta[i] - tmp);
		}
	}
	cout << tot - mx << endl;
	return 0;
}
