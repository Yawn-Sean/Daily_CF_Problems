#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	i64 b1, q, l, m;
	cin >> b1 >> q >> l >> m;
	set<i64> ss;
	for (int i = 0; i < m; i++) { i64 x; cin >> x; ss.insert(x); }
	
	if (abs(b1) > l) {
		cout << "0";
	} else if (b1 == 0) {
		cout << (ss.find(0) != ss.end() ? "0" : "inf");
	} else if (q == -1) {
		cout << ((ss.find(b1) != ss.end()) and (ss.find(-b1) != ss.end()) ? "0" : "inf");
	} else if (q == 0) {
		if (ss.find(0) != ss.end()) {
			if (ss.find(b1) != ss.end()) {
				cout << "0";
			} else {
				cout << "1";
			}
		} else {
			cout << "inf";
		}
	} else if (q == 1) {
		cout << (ss.find(b1) != ss.end() ? "0" : "inf");
	} else {
		int ans = 0;
		while (abs(b1) <= l) {
			if (ss.find(b1) == ss.end()) {
				ans++;
			}
			b1 *= q;
		}
		cout << ans;
	}
	
	return 0;
}
