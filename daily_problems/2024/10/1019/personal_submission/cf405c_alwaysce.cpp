#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<vector<int>> mat(n, vector<int>(n));
	int tot = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			if (i == j) {
				tot += mat[i][j];
				tot %= 2;
			}
		}
	}
	
	int q;
	cin >> q;
	while (q--) {
		int op;
		cin >> op;
		if (op == 1 or op == 2) {
			int i;
			cin >> i;
			i--;
			tot -= mat[i][i];
			tot += 1 - mat[i][i];
			mat[i][i] = 1 - mat[i][i];
			tot = (tot + 2) % 2;
		} else {
			cout << tot;
		}
	}

    return 0;
}
