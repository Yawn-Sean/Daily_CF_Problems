#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	cin >> n;
	vector<int> d(n);
	for (auto&x: d) { cin >> x; }
	
	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&](int a, int b) {
		return d[a] > d[b];
	});
	
	vector<pair<int,int>> ans;
	int idx = n, cnt1 = 0;
	
	for (int i = 0; i < n; i++) {
		int ux = order[i];
		if (d[ux] == 1) {
			++cnt1;
			if (cnt1 >= 2) {
				idx = i;
				break;
			}
		}
	}
	
	for (int i = 0; i < idx - 1; i++) {
		int ux = order[i];
		int vx = order[i+1];
		ans.emplace_back(ux, vx);
		--d[ux]; --d[vx];
	}
	if (idx < n) {
		ans.emplace_back(order[0], order[idx]);
		--d[order[0]]; --d[order[idx]];
	}
	
	int ansL = ans.size();
	int j = 0;
	for (int i = idx + 1; i < n; i++) {
		while (j < idx) {
			if (d[order[j]] > 0) {
				ans.emplace_back(order[i], order[j]);
				--d[order[i]];
				--d[order[j]];
				break;
			} else {
				j++;
			}
		}
	}
	
	int ansS = ans.size();
	if (ansS == n - 1) {
		cout << "YES " << ansL << '\n';
		cout << ans.size() << '\n';
		for (auto&pr: ans) {
			cout << pr.first+1 << ' ' << pr.second+1 << '\n';
		}
	} else {
		cout << "NO";
	}
	
	return 0;
}
