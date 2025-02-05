#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		int b, n;
		cin >> b >> n;
		
		bool flag = true;
		i64 cur = 1ll;
		
		for (int i = 1; i <= n; i++) {
			cur = (cur * b) % n;
			if (cur == 0) {
				cout << "1 " << i << '\n';
				flag = false;
				break;
			}
			if (cur == 1) {
				cout << "2 " << i << '\n';
				flag = false;
				break;
			}
			if (cur == n - 1) {
				cout << "3 " << i << '\n';
				flag = false;
				break;
			}
		}
		if (flag) {
			cout << "0\n";
		}
	}
	return 0;
}
