#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	i64 n, l, r;
	cin >> n >> l >> r;
	auto f = [&](auto self, i64 pos, i64 x, i64 lp, i64 rp) -> i64{
		if (lp == rp) return x;
		i64 m = (rp + lp) / 2;
		if (pos == m) return x % 2;
		else if (pos < m) return self(self, pos, x / 2, lp, m - 1);
		else return self(self, pos, x / 2, m + 1, rp);
	};
	auto g = [&](auto self, i64 x) -> i64{
		if (x <= 1) return 1;
		return 2 * self(self, x / 2) + 1;
	};
	i64 cnt = g(g, n);
	i64 ans = 0;
	for (i64 i = l; i <= r; i ++){
		ans += f(f, i, n, 1, cnt);
	}
	cout << ans << endl;
	return 0;
}
