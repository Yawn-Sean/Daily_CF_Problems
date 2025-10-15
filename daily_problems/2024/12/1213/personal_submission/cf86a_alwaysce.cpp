#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	/*
		abcd
		(9-a)(9-b)(9-c)(9-d)
		
		x * (9..9-x)
		=> x * (10^k-1 - x) 找最大值
	*/
	i64 l, r;
	cin >> l >> r;
	i64 x = 1ll;
	while (x <= r) {
		x *= 10ll;
	}
	x -= 1;
	
	i64 mid = x / 2;
	if (mid <= l) {
		cout << l * (x - l);
	} else if (r <= mid) {
		cout << r * (x - r);
	} else {
		cout << max(mid * (x - mid), (mid + 1) * (x - mid - 1));
	}
	
	return 0;
}
