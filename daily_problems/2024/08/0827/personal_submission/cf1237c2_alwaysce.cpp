#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<vector<int>> pt(n, vector<int>(3));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> pt[i][j];
		}
	}
	
	vector<int> ids(n);
	iota(ids.begin(), ids.end(), 0);
	
	function<int(vector<int>&, int)> gao = [&](vector<int>& ids, int d) {
		// distinct
		if (d == 3) {
			return ids[0];
		}
		
		map<int, vector<int>> mp;
		// 按照d维度排序
		for (auto& x: ids) {
			mp[pt[x][d]].push_back(x);
		}
		
		vector<int> a;
		// for same-d, solve on d + 1
		for (auto& q: mp) {
			int cur = gao(q.second, d + 1);
			if (cur != -1) {
				a.push_back(cur);
			}
		}
		
		for (int i = 0; i + 1 < (int)a.size(); i += 2) {
			cout << a[i] + 1 << ' ' << a[i + 1] + 1 << '\n';
		}
		
		return (a.size() % 2 == 1 ? a.back() : -1);
	};
	
	gao(ids, 0);
    return 0;
}
