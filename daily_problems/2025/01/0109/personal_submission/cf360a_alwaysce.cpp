#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m;
	cin >> n >> m;
	vector<int> tp(m), l(m), r(m), val(m);
	for (int i = 0; i < m; i++) {
		cin >> tp[i] >> l[i] >> r[i] >> val[i];
	}
	
	vector<i64> diff(n + 1), ans(n + 1, inf);
	for (int i = 0; i < m; i++) {
		if (tp[i] == 1) {
			for (int j = l[i]; j <= r[i]; j++) {
				diff[j] += val[i];
			}
		} else {
			// 每个位置上取最大?
			for (int j = l[i]; j <= r[i]; j++) {
				ans[j] = min(ans[j], val[i] - diff[j]);
			}
		}
	}
	
	vector<i64> tmp = ans;
	for (int i = 0; i < m; i++) {
		if (tp[i] == 1) {
			for (int j = l[i]; j <= r[i]; j++) {
				tmp[j] += val[i];
			}
		} else {
			i64 cur = -inf;
			for (int j = l[i]; j <= r[i]; j++) {
				cur = max(cur, tmp[j]);
			}
			if (cur != val[i]) {
				cout << "NO";
				return 0;
			}
		}
	}
	
	cout << "YES\n";
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	return 0;
}
