#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int n;
	cin >> n;
	vector<int> c(n), p(n);
	for (int i = 0; i < n; i ++){
		cin >> c[i] >> p[i];
	}
	int k;
	cin >> k;
	vector<int> r(k);
	for (auto &x : r){
		cin >> x;
	}
	vector<int> pos(k);
	iota(pos.begin(), pos.end(), 0);
	sort(pos.begin(), pos.end(), [&](int i, int j){
		return r[i] < r[j];
	});
	vector<int> used(n);
	vector<pair<int, int>> ans;
	int tot = 0;
	for (int i = 0; i < k; i ++){
		int x = r[pos[i]];
		int choose = -1, mx = 0; 
		for (int j = 0; j < n; j ++){
			if (!used[j] && c[j] <= x && mx < p[j]){
				mx = p[j];
				if (choose != -1)
					used[choose] = 0;
				choose = j;
				used[j] = 1;
			}
		}
		if (choose != -1){
			tot += mx;
			ans.push_back({choose, pos[i]});
		}
	}
	cout << ans.size() << " " << tot << endl;
	for (auto [x, y] : ans){
		cout << x + 1 << " " << y + 1 << endl;
	}
	return 0;
}
