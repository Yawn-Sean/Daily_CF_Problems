#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	

	/*
		a, b, c
		min(x, y) + (max(x,y)-min(x,y)/2) * 2
		x和y的奇偶性一样就可以这么操作
	*/
	i64 a, b, c;
	cin >> a >> b >> c;
	i64 ans = inf;
	if (a % 2 == b % 2) { ans = min(ans, max(a, b)); }
	if (b % 2 == c % 2) { ans = min(ans, max(b, c)); }
	if (a % 2 == c % 2) { ans = min(ans, max(a, c)); }
	
	cout << ans;
	return 0;
}
