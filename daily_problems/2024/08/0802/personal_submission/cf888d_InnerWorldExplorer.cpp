#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

i64 comb(int n, int k) {
	if (k > n) return 0;
	if (k * 2 > n) k = n - k;
	if (k == 0) return 1;

	i64 result = n;
	for ( int i = 2; i <= k; ++i ) {
		result *= (n - i + 1);
		result /= i;
	}
	return result;
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, k;
	cin >> n >> k;
	i64 ans = 1;
	if (k >= 2) {
		ans += comb(n, 2);
	}
	if (k >= 3) {
		ans += comb(n, 3) * 2;
	}
	if (k >= 4) {
		ans += comb(n, 4) * 9;
	}
	cout << ans << endl;
	return 0;
}
