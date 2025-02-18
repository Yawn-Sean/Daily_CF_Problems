#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1000000007;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int x, y, n;
	cin >> x >> y >> n;
	
	i64 ans_a = 0, ans_b = 1;
	auto check = [&](i64 up, i64 down) {
		// up/down - x/y
		// ans_a/ans_b - x/y
		i64 lhs = abs(up * y - down * x) * ans_b;
		i64 rhs = abs(ans_a * y - ans_b * x) * down;
		return lhs < rhs;
	};
	
	for (int b = 1; b <= n; b++) {
		i64 mul = 1ll * x * b;
		if (mul % y == 0) {
			ans_a = mul / y;
			ans_b = b;
			break;
		} else {
			i64 a1 = mul / y;
			i64 a2 = a1 + 1;
			
			// dif1 = bx - a1y /b*y
			// old_dif = 
			if (check(a1, b)) {
				ans_a = a1;
				ans_b = b;
			}
			if (check(a2, b)) {
				ans_a = a2;
				ans_b = b;
			}
		}
	}
	cout << ans_a << "/" << ans_b << '\n';
    return 0;
}
