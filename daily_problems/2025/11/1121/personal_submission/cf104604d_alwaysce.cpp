#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t;
	cin >> t;
	while (t--) {
		i64 a, b;
		cin >> a >> b;
		if (a > b) { swap(a, b); }
		if (a * 2ll < b) {
			cout << "NO\n";
		}
		else if (a == b) {
			if (a % 2 == 0) {
				cout << "SI\n";
			} else {
				cout << "NO\n";
			}
		} else {
			if (a % (b - a) != 0) {
				cout << "NO\n";
			} else {
				bool ok = false;
				for (int i = 2; i <= 4; i++) {
					if (b % i == 0) {
						i64 x = a - b / i;
						if (x > 0 && b % x == 0) {
							ok = true;
						}
					}
				}
				cout << (ok ? "SI" : "NO") << '\n';
			}
		}
	}
	return 0;
}
