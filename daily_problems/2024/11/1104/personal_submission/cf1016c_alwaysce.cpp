#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<vector<i64>> a(2, vector<i64>(n));
	for (int i = 0; i < n; i++) {
		cin >> a[0][i];
	}
	for (int i = 0; i < n; i++) {
		cin >> a[1][i];
	}

	/*
		观察到一旦连续向右移动两次 后面的路径就固定了
	*/
	
	vector<i64> pre1(n + 1, 0), pre2(n + 1, 0);
	for (int i = 0; i < n; i++) {
		pre1[i + 1] = pre1[i] + a[0][i];
		pre2[i + 1] = pre2[i] + a[1][i];
	}
	// 第1行-> [n] <- 的和 / 第2行->[n]<-的和
	
	// t a[x] + (t+1)a[x+1]+....
	//          (t+2)a[x+1]+... +a[n] + ... + b[..] 
	// 少了 pre1[n] - pre1[x+1] && pre2[n] - pre2[x+1]
	// 多了 2i * a[x] + 2n-1*b[x]
	vector<i64> dp1(n + 1, 0), dp2(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		dp1[i] = dp1[i + 1] - (pre1[n] - pre1[i + 1]) - (pre2[n] - pre2[i + 1]) + 2ll * i * a[0][i] + (2ll * n - 1) * a[1][i];
		dp2[i] = dp2[i + 1] - (pre1[n] - pre1[i + 1]) - (pre2[n] - pre2[i + 1]) + 2ll * i * a[1][i] + (2ll * n - 1) * a[0][i];
	}
	
	i64 ans = dp1[0];
	i64 cur = 0;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			cur += (2ll * i * a[1][i]) + (2ll * i + 1ll) * a[0][i];
			ans = max(ans, cur + dp1[i + 1]);
		} else {
			cur += (2ll * i * a[0][i]) + (2ll * i + 1ll) * a[1][i];
			ans = max(ans, cur + dp2[i + 1]);
		}
	}
	cout << ans;
    return 0;
}
