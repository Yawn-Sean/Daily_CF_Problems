#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	for (auto& v: a) { cin >> v; }
	
	vector<int> ends;
	ends.push_back(2e9);
	
	vector<vector<int>> ans(n + 1);
	for (int i = 0; i < n; i++) {
		int left = 0, right = ends.size();
		while (left < right) {
			int mid = (left + right) / 2;
			if (ends[mid] > a[i]) {
				left = mid + 1;
			} else {
				right = mid;
			}
		}
		if (left == (int)ends.size()) {
			ends.push_back(a[i]);
		} else {
			ends[left] = a[i];		
		}
		ans[left].push_back(a[i]);
	}
	
	for (int i = 1; i <= n; i++) {
		for (auto& x: ans[i]) {
			cout << x << ' ';
		}
		cout << '\n';
	}
    return 0;
}
