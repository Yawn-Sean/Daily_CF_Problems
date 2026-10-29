#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	string s;

	cin >> n >> s;

	bool flg = false;

	for (int i = 1; i < n; i ++) flg |= (s[i] == s[i - 1]);

	if (!flg) cout << n;
	else {
		int cur = 0;

		for (auto &c: s) {
			if (c == 'G') cur += 1;
			else cur += 2;
		}

		cout << (cur % 3 == 0 ? 2 : 1);
	}

	return 0;
}