#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;
template <typename T>
struct Fenwick {
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int q;
	cin >> q;
	
	map<int, vector<vector<int>> > mp;
	for (int i = 0; i < q; i++) {
		int a, t, x;
		cin >> a >> t >> x;
		mp[x].push_back({a, t, i});	
	}

	// 每个数字都是独立的
	// 对于每个数字分组
	// 查询a=3 时刻t 小于t的累加和删除操作总和(BIT)
		
	vector<int> ans(q, -1);
	for (auto& pr: mp) {
		vector<int> time;
		for (auto& x: pr.second) {
			time.push_back(x[1]);
		}
		sort(time.begin(), time.end());
		
		Fenwick<int> f(time.size());
		for (auto& x: pr.second) {
			int idx = lower_bound(time.begin(), time.end(), x[1]) - time.begin();
			if (x[0] == 1) {
				f.add(idx, 1);
			} else if (x[0] == 2) {
				f.add(idx, -1);
			} else {
				ans[x[2]] = f.sum(idx + 1);
			}
		}
	}
	
	for (auto& v: ans) {
		if (v != -1) {
			cout << v << '\n';
		}
	}
    return 0;
}
