#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

void solve() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	if (s[0] == '0') {
		cout << "-1\n";
		return;
	}

	int cnt = count(s.begin(), s.end(), '1');
	if (cnt == n) {
		cout << string(n, 'a') << "\n";
		return;
	} if (cnt == 2 && s[0] == s.back()) {
		cout << string((n + 1) / 2 - 1, 'a') << string(1 + (n % 2 == 0), 'b') << string((n + 1) / 2 - 1, 'a') << "\n";
		return;
	}

	int v = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] - '0' == (i & 1)) {
			v = 1;
		}
	}

	if (cnt == 1) {
		cout << string(n - 1, 'a') << "b\n";
	} else if (!v) {
		int vw = 0;
		for (int i = 0; i < n; i++) {
			cout << (char)(vw + 'a');
			vw = (vw + 1) % 2;
		}
		cout << "\n";
	} else {
		cout << "-1\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}