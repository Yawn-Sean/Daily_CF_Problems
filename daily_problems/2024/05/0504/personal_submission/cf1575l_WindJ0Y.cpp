#include <bits/stdc++.h>
using namespace std;

void solve() {
	int n; cin >> n;

	vector<vector<int>> gp_nums(n);

	for (int i = 0; i < n; i++) {
		int t; cin >> t; t--;
		if (i - t >= 0) {
			gp_nums[t].push_back(i - t);
		}
	}

	vector<int> lis {};
	for (auto nums : gp_nums) {
		for (int i = nums.size() - 1; i >= 0; i--) {
			int elm = nums[i];
			auto it = upper_bound(lis.begin(), lis.end(), elm);
			if (it == lis.end()) {
				lis.push_back(elm);
			} else {
				*it = elm;
			}
		}
	}

	cout << lis.size() << "\n";
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    while (T--) {
        solve();
    }

}