#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int q;
	std::cin >> q;
	i64 v = 0, flag = 1, flag1 = -1;
	i64 ans = 0;
	int d = 0;
	std::stack<int> vv;
	while (q--) {
		int op;
		std::cin >> op;
		if (op == 1) {
			i64 x;
			std::cin >> x;
			v = x;
			while (vv.size() != 0 && vv.top() < v) {
				vv.pop();
				ans++;
			}
		}
		else if (op == 2) {
			if (!flag) {
				flag = 1;
				ans += d;
				d = 0;
			}
		}
		else if (op == 3) {
			i64 x;
			std::cin >> x;
			vv.push(x);
			while (vv.size() != 0 && vv.top() < v) {
				vv.pop();
				ans++;
			}
		}
		else if (op == 4) {
			flag = 1;
			d = 0;
		}
		else if (op == 5) {
			while (vv.size() != 0) {
				vv.pop();
			}
		}
		else {
			flag = 0;
			d++;
		}

	}
	std::cout << ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
