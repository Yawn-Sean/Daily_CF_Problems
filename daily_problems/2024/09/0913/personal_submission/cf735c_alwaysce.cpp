#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	i64 n;
	cin >> n;
	
	i64 f0 = 1, f1 = 2;
	i64 ans = 0;
	while (f1 <= n) {
		i64 tmp = f0;
		f0 = f1;
		f1 = tmp + f1;
		ans++;
	}
	cout << ans << '\n';
	return 0;
}
