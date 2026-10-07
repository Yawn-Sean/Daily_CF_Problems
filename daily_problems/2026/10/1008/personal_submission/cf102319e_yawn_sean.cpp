#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k;
	cin >> n >> k;

	string s(n, '0');
	for (int i = 0; i < 3; i ++) s[i] = '1';

	int bound = 0;

	for (int i = 3; i < n; i ++) {
		s[i] = '1';
		cout << "? " << s << endl;
		int x; cin >> x;

		if (x) {
			bound = i;
			break;
		}
	}

	for (int i = 0; i < bound; i ++) {
		s[i] = '0';
		cout << "? " << s << endl;
		int x; cin >> x;

		if (!x) s[i] = '1';
	}

	auto tmp = s;
	tmp[bound] = '0';

	for (int i = bound + 1; i < n; i ++) {
		tmp[i] = '1';
		cout << "? " << tmp << endl;
		int x; cin >> x;

		if (x) s[i] = '1';
		tmp[i] = '0';
	}

	cout << "! " << s;

	return 0;
}