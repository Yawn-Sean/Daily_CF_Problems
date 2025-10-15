#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9+7;
int inf = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a, b, w, x, c;
	cin >> a >> b >> w >> x >> c;
	/*
		b>=x -> b = b - x
		b < x -> a = a - 1, b = w-x+b = b + (w-x)
		
		发生第二种操作的次数y
		b + (w-x) y = x(c-a)
		增大次数 y = x(c-a) - b / (w - x)		
		=> ans = ceil(c - a + y) = ceil((c-a)w-b / (w-x))
	*/
	if (c <= a) {
		cout << 0;
	} else {
		i64 ans = (1ll * (c - a) * w - b + (w - x - 1)) / (w - x);
		cout << ans;
	}
	return 0;
}
