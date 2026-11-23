#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	if (n == 2 || n == 4) return cout << "NO", 0;

	cout << "YES\n";

	if (n == 6) {
		cout << "ABBBBB\n";
		cout << "ADDEEE\n";
		cout << "CDDFFF\n";
		cout << "CDDFFF\n";
		cout << "CDDFFF\n";
		cout << "CDDFFF\n";
	}
	else if (n & 1) {
		vector<string> grid(n, string(n, 'E'));

		for (int i = 0; i < n / 2; i ++) {
			for (int j = 0; j <= i; j ++) grid[i][j] = (i & 1) ? 'A' : 'C';
			for (int j = i + 1; j < n; j ++) grid[i][j] = (i & 1) ? 'B' : 'D';
		}

		for (auto &s: grid) cout << s << '\n';
	}
	else {
		vector<string> grid(n, string(n, 'H'));

		for (int i = 0; i < n / 2 - 2; i ++) {
			for (int j = 0; j <= i; j ++) grid[i][j] = (i & 1) ? 'A' : 'C';
			for (int j = i + 1; j < n; j ++) grid[i][j] = (i & 1) ? 'B' : 'D';
		}

		for (int i = 0; i < n; i ++) grid[n / 2 - 2][i] = 'E';
		for (int i = n / 2 - 1; i < n; i ++) grid[i][0] = 'F';

		for (int i = n / 2 - 1; i <= n / 2; i ++) {
			for (int j = 1; j < n; j ++) {
				grid[i][j] = 'G';
			}
		}

		for (auto &s: grid) cout << s << '\n';
	}

	return 0;
}