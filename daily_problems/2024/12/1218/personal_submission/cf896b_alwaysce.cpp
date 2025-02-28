#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
const int inf = 1000000007;
i64 mod = 1e9+7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, c;
	cin >> n >> m >> c;
	
	int mid = c / 2, not_used = n;
	vector<int> ans(n, -1);
	while (not_used > 0) {
		int v;
		cin >> v;
		if (v <= mid) {
			for (int i = 0; i < n; i++) {
				if (ans[i] == -1 or ans[i] > v) {
					cout << i + 1 << endl;
					not_used -= (ans[i] == -1);
					ans[i] = v;
					break;
				}
			}
		} else {
			for (int i = n - 1; i >= 0; i--) {
				if (ans[i] == -1 or ans[i] < v) {
					cout << i + 1 << endl;
					not_used -= (ans[i] == -1);
					ans[i] = v;
					break;
				}
			}
		}
	}
	return 0;
}
