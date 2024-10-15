#include <bits/stdc++.h>
using namespace std;

#define ve vector
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; a >= b; i--)

inline int read() {
	int x;
	cin >> x;
	return x;
}

void solve() {
	int n = read(), a = read(), b = read(), k = read(), cur = 0;
	string s;
	cin >> s;
	ve<int> va;
	rep(i, 0, n) {
		char c = s[i];
		if (c == '0') {
			cur++;
			if (cur == b) {
				va.emplace_back(i + 1);
				cur = 0;
			}
		} else {
			cur = 0;
		}
	}
	int m = va.size();
	cout << m - a + 1 << '\n';
	rep(i, 0, m - a + 1) {
		cout << va[i] << " \n"[i == m - a + 1];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}