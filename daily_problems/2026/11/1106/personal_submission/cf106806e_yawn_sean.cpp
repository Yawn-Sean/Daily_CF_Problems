#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	string s;
	cin >> s;

	int n = s.size();

	for (int i = 1; i < n; i ++) {
		if (n % i == 0) {
			bool flg = true;
			for (int j = 0; j < n; j ++) {
				if (s[j] != s[j % i]) {
					flg = false;
				}
			}

			if (flg) {
				if (i == 1) {
					cout << n << '\n';
					for (int i = 0; i < n; i ++) cout << s[i] << " \n"[i == n - 1];
				}
				else {
					cout << 2 << '\n';
					cout << s.substr(0, i + 1) << ' ' << s.substr(i + 1) << '\n';
				}
				return 0;
			}
		}
	}

	cout << 1 << '\n' << s << '\n';

	return 0;
}