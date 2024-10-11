#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

constexpr int MOD = 1000000007;
const i64 BIG = 1e18;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int t, l, r;
	cin >> t >> l >> r;
	vector<i64> f(r + 1, BIG);
	f[1] = 0;
	for (i64 i = 1; i <= r; i ++) {
		for (i64 j = 2; j * i <= r; j ++) {
			i64 tmp = f[i] + i * j * (j - 1) / 2;
			if (tmp < f[i * j])
				f[i * j] =  tmp;
		}
	}
	i64 ans = 0;
	for (int i = r; i >= l; i --) {
		ans = (ans * t + f[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}
