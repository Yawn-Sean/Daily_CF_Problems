#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	/*
		对于任何一对相邻的鲨鱼 i 和 j 来说
		乘积 si·sj 能被 p 整除
	*/
	int n;
	cin >> n;
	
	int p;
	cin >> p;
	
	vector<long double> prob(n);
	for (int i = 0; i < n; i++) {
		int l, r;
		cin >> l >> r;
		prob[i] = (long double)1.0 * (r / p - (l - 1) / p) / (r - l + 1);
	}
	
	long double ans = 0.0;
	for (int i = 0; i < n; i++) {
		ans += prob[i];
		ans += (prob[(i + 1) % n]);
		ans -= (prob[i] * prob[(i + 1) % n]);
	}
	
	cout << fixed << setprecision(10) << ans * 2000.0;
	
    return 0;
}
