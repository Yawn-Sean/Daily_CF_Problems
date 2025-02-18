#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n;
	cin >> n;
	vector<int> a(n);
	vector<vector<int>> ans;
	map<int, int> suf;
	int x;
	for (int i = 0, j = 0; i < n; i ++) {
		cin >> x;
		auto it = suf.lower_bound(x);
		if (it != suf.begin()) {
			it --;
			int less = it->first;
			ans[suf[less]].emplace_back(x);
			suf[x] = suf[less];
			suf.erase(less);
		} else {
			ans.emplace_back(vector<int> {x});
			suf[x] = j ++;
		}
	}
	for (auto &v : ans) {
		for (int i = 0; i < v.size(); i ++) {
			cout << v[i] << " \n"[i == v.size() - 1];
		}
	}
	return 0;
}
