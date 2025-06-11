#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	/*
		
	*/
	int n, l, k;
	cin >> n >> l >> k;
	vector<int> p(n);
	for (auto& x: p){
		cin >> x;
	}
	
	vector<int> a(n);
	for (auto& x: a) {
		cin >> x;
	}
	
	vector<vector<long double>> dp(n + 1, vector<long double>(205, 0.0));
	vector<vector<long double>> ndp(n + 1, vector<long double>(205, 0.0));
	dp[0][k] = 1.0;
	
	for (int i = 0; i < n; i++) {
		if (a[i] >= 0) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= 200; k++) {
					if (dp[j][k] > 0.0) {
						long double win = (long double)1.0 * p[i] / 100;
						ndp[j][k] += (-win + 1.0) * dp[j][k];
						ndp[j + 1][min(k + a[i], 200)] += win * dp[j][k];
					}
				}
			}
			
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= 200; k++) {
					dp[j][k] = ndp[j][k];
					ndp[j][k] = 0.0;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (a[i] == -1) {
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= 200; k++) {
					if (dp[j][k] > 0.0) {
						long double win = (long double)1.0 * p[i] / 100;
						ndp[j][k] += (-win + 1.0) * dp[j][k];
						if (k > 0) {
							ndp[j + 1][k - 1] += win * dp[j][k];
						}
					}
				}
			}
			
			for (int j = 0; j <= n; j++) {
				for (int k = 0; k <= 200; k++) {
					dp[j][k] = ndp[j][k];
					ndp[j][k] = 0.0;
				}
			}
		}
	}
	
	long double ans = 0.0;
	for (int i = l; i <= n; i++) {
		for (int j = 0; j <= 200; j++) {
			ans += dp[i][j];
		}
	}
	cout << fixed << setprecision(10) << ans;
	return 0;
}
