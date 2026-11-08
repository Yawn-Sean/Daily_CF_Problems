#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> ans(n, -1);

		for (int val = 0; val <= n; val ++) {
			vector<int> idxs;
			for (int i = 0; i < n; i ++) {
				if (ans[i] == -1) {
					idxs.emplace_back(i);
				}
			}

			int pt = 0, query_res;

			while (pt < idxs.size()) {
				cout << "? " << idxs.size() - pt << ' ' << val << '\n';
				for (int i = pt; i < idxs.size(); i ++) cout << idxs[i] + 1 << ' ';
				cout << '\n';
				for (int i = 0; i < val; i ++) cout << i << ' ';
				cout << endl;
				cin >> query_res;
				if (query_res == val) break;

				int left = pt, right = idxs.size() - 1;
				while (left <= right) {
					int mid = (left + right) / 2;
					cout << "? " << mid - pt + 1 << ' ' << val << '\n';
					for (int i = pt; i <= mid; i ++) cout << idxs[i] + 1 << ' ';
					cout << '\n';
					for (int i = 0; i < val; i ++) cout << i << ' ';
					cout << endl;
					cin >> query_res;

					if (query_res == val) left = mid + 1;
					else right = mid - 1;
				}

				ans[idxs[left]] = val;
				pt = left + 1;
			}
		}

		cout << "!";
		for (auto &x: ans) cout << ' ' << x;
		cout << endl;
	}

	return 0;
}