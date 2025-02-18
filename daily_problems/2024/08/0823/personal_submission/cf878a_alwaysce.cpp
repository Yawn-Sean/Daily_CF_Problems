#include <bits/stdc++.h>
using i64 = long long;
using namespace std;

i64 mod = 1000000007;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	int v0 = 0, v1023 = 1023;
	while (n--) {
		char op;
		int x;
		cin >> op >> x;
		if (op == '|') {
			v0 |= x, v1023 |= x;
		} else if (op == '&') {
			v0 &= x, v1023 &= x;
		} else {
			v0 ^= x, v1023 ^= x;
		}
	}
	
	int and_op = 1023, or_op = 0, xor_op = 0;
	for (int i = 0; i < 10; i++) {
		int c0 = (v0 >> i) & 1;
		int c1 = (v1023 >> i) & 1;
		// (0, 1) => (0, 0) set 0
		// (0, 1) => (1, 1) set 1
		// (0, 1) => (1, 0) flip
		// (0, 1) => (0, 1) 不变
		if (c0 == 0 and c1 == 0) {
			and_op &= (~(1 << i));
		} else if (c0 == 1 and c1 == 1) {
			or_op |= (1 << i);
		} else if (c0 == 1 and c1 == 0) {
			xor_op |= (1 << i);
		}
	}
	
	cout << 3 << '\n';
	cout << "| " << or_op << '\n';
	cout << "& " << and_op << '\n';
	cout << "^ " << xor_op << '\n';
	return 0;
}
