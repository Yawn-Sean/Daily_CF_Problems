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

	if (n <= 2) {
		cout << "Bob\n";
		return;
	}

	for (int i = 0; i < n - 1; i++) {
		if (s[i] != s[0]) {
			cout << "Alice\n";
			return;
		}
	}

	cout << "Bob\n";
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