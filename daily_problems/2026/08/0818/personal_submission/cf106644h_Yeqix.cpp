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
	s = " " + s;

	auto print = [&](char c)->void{
		if (c == 'B') {
			cout << "Doludu\n";
		} else{
			cout << "DoIudu\n";
		}
	};

	if (n % 2 == 0) {
		if (s[n / 2] == s[n / 2 + 1]) {
			print(s[n / 2]);
		} else {
			print('B');
		}
	} else {
		int v = (n + 1) / 2;
		if (s[v] == 'B' && (s[v - 1] == 'B' || s[v + 1] == 'B')) {
			print(s[v]);
		} else {
			print('R');
		}
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