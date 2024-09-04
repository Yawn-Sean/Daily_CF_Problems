#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, m, k;
	cin >> n >> m >> k;
	if (n + m - 2 < k) {
		cout << -1 << endl;
		return 0;
	}
	auto f = [&](int x){
		return 1LL * x * (m / max(1, (k - n / x + 2)));
	};
	long long ans = 0;
	for (int i = 1; i * i <= n; i ++){
		ans = max(ans, f(i));
		ans = max(ans, f(n / i));
	}
	cout << ans << endl;
	return 0;
}
