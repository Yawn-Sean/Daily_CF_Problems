#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		string s;
		cin >> n >> s;

		vector<int> ops;
		int l = 0;

		for (int i = 0; i < n; i ++) {
			if (s[i] == 'D') {
				for (int j = i; j >= l; j --) ops.emplace_back(j);
				l = i + 1;
				if (i + 1 < n) s[i + 1] = s[i + 1] == 'B' ? 'D' : 'B';
			}
		}

		if (ops.size() == n) {
			cout << "Y\n";
			for (int i = 0; i < n; i ++) cout << ops[i] + 1 << " \n"[i == n - 1];
		}
		else cout << "N\n";
	}

	return 0;
}