#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;
int inf = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, m, k, q;
	cin >> n >> m >> k >> q;
	
	vector<vector<int>> preS(n + 1, vector<int>(m + 1, 0));
	vector<vector<i64>> A(n + 1, vector<i64>(m + 1, inf));
	vector<int> xs(q), ys(q), ts(q);
	
	for (int i = 0; i < q; i++) {
		cin >> xs[i] >> ys[i] >> ts[i];
		A[xs[i]][ys[i]] = ts[i];
	}
	
	auto check = [&](i64 t) {
		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= m; j++) {
				preS[i][j] = 0;
			}
		}
		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				preS[i][j] = (A[i][j] <= t) + preS[i - 1][j] + preS[i][j - 1] - preS[i - 1][j - 1];
			}
		}
		
		// (x1, y1) (x2, y2)元素和 >= k*k
		for (int i = k; i <= n; i++) {
			for (int j = k; j <= m; j++) {
				int tot = preS[i][j] - preS[i - k][j] - preS[i][j - k] + preS[i - k][j - k];
				if (tot >= k * k) {
					return true;
				}
			}
		}
		return false;
	};
	
	i64 left = 0, right = inf + 1;
	i64 ans = inf;
	while (left < right) {
		i64 mid = (left + right) / 2;
		if (not check(mid)) {
			left = mid + 1;
		} else {
			right = mid;
			ans = mid;
		}
	}
	
	cout << (ans == inf ? -1 : ans);
    return 0;
}
