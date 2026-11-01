#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	vector<pair<int, int>> tags = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

	int best = 5;
	int chosen_msk = 0;

	for (int mask = 0; mask < 16; mask ++) {
		bool valid = true;

		for (int j = 0; j < n; j ++) {
			bool covered = false;
			auto [x, y] = pts[j];

			for (int k = 0; k < 4; k ++) {
				if ((mask >> k) & 1) {
					auto [dx, dy] = tags[k];
					if (x * dx + y * dy > 0) covered = true;
				}
			}

			if (!covered) valid = false;
		}

		if (valid && __popcount(mask) < best) {
			best = __popcount(mask);
			chosen_msk = mask;
		}
	}

	vector<int> chosen(4);
	for (int i = 0; i < 4; ++i) chosen[i] = (chosen_msk >> i) & 1;

	cout << best << '\n';

	if (chosen[0]) {
		if (chosen[3]) cout << "-0.4 0.6 1500.0 0.6 -0.4 1500.0 1500.0 1500.0\n";
		else cout << "-1500.0 0.6 1500.0 0.6 -1500.0 1500.0 1500.0 1500.0\n";
	}
	if (chosen[1]) {
		if (chosen[0]) cout << "0.6 0.4 1500.0 0.4 0.6 -1500.0 1500.0 -1500.0\n";
		else cout << "0.6 1500.0 1500.0 1500.0 0.6 -1500.0 1500.0 -1500.0\n";
	}
	if (chosen[2]) {
		if (chosen[1]) cout << "-1500.0 -0.6 0.4 -0.6 -1500.0 -1500.0 0.4 -1500.0\n";
		else cout << "-1500.0 -0.6 1500.0 -0.6 -1500.0 -1500.0 1500.0 -1500.0\n";
	}
	if (chosen[3]) {
		if (chosen[2]) cout << "-1500.0 -0.4 -0.6 -0.4 -1500.0 1500.0 -0.6 1500.0\n";
		else cout << "-1500.0 -1500.0 -0.6 -1500.0 -1500.0 1500.0 -0.6 1500.0\n";
	}

	return 0;
}