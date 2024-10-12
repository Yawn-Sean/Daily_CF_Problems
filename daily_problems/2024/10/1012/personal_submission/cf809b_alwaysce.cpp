#include <bits/stdc++.h>
using i64 = long long;
using ui64 = unsigned long long;
using namespace std;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	auto q = [&](int x, int y) {
		cout << 1 << ' ' << x << ' ' << y << endl;
		string s;
		cin >> s;
		return s[0] == 'T';
	};
	
	auto search = [&](int l, int r) {
		while (l < r) {
			int m = (l + r) / 2;
			if (q(m, m + 1)) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		return r;
	};
	
	int n, k;
	cin >> n >> k;
	int x, y;
	x = search(1, n);
	y = search(1, x - 1);
	if (y == 0 or q(y, x) == false) {
		y = search(x + 1, n);
	}
	cout << 2 << ' ' << x << ' ' << y;
	return 0;
}
