#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

int main()
{
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	i64 m;
	cin >> m;

	auto check = [&](i64 x){
		i64 i = 0, j = cbrtl(x);
		while (i < j){
			i64 md = (i + j + 1) / 2;
			if (md * md > x || md * md * md > x){
				j = md - 1;
			}else{
				i = md;
			}
		}
		i64 cnt = 0;
		for (i64 t = i; t > 1; t --){
			cnt += x / (t * t * t);
		}
		return cnt;
	};

	i64 l = 0, r = i64(1e18);
	while (l < r){
		i64 mid = (l + r) / 2;
		if (check(mid) < m){
			l = mid + 1;
		}else{
			r = mid;
		}
	}
	if (check(l) == m) cout << l;
	else cout << -1;
	cout << endl;
	return 0;
}
