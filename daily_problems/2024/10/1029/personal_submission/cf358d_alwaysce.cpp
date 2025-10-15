#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<int> a(n), b(n), c(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> c[i];
	}
	
	// i-1, i | i,i+1的先后顺序
	// dp0: (i,i+1)先放i
	// dp1: (i,i+1)先放i+1
	// (i,i+1) -> (i+1,i+2)
	int dp0 = a[0], dp1 = b[0];
	for (int i = 1; i < n; i++) {
		int tmp = max(dp0 + b[i], dp1 + a[i]);
		// (i) [i+1] (i+2)
		dp1 = max(dp0 + c[i], dp1 + b[i]);
		dp0 = tmp;
	}
	
	cout << dp0;
	return 0;
}
