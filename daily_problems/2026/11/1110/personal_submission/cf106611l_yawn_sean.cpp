#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	string s;

	cin >> n >> s;

	vector<int> stk;

	for (int i = 0; i < n; i ++) {
		if (s[i] >= '0' && s[i] <= '2') {
			stk.emplace_back(i);
		}
	}

	int ans = 0;

	while (!stk.empty()) {
		int u = stk.back(); stk.pop_back();

		vector<int> dirs;
		if (s[u] >= '0' && s[u] <= '2') dirs = {0};
		else dirs = {-1, 1};

		for (auto &nx: dirs) {
			int x = u + nx;

			if (x >= 0 && x < n && s[x] >= '0' && s[x] <= '2') {
				int total = s[x] - '0';
				vector<int> tmp;

				for (auto &dx: {-1, 1}) {
					if (x + dx >= 0 && x + dx < n) {
						if (s[x + dx] == '*') total --;
						else if (s[x + dx] == '?') tmp.emplace_back(x + dx);
					}
				}

				if (total == 0) {
					for (auto &v: tmp) {
						s[v] = ' ';
						ans ++;
						stk.emplace_back(v);
					}
				}
				else if (total == tmp.size()) {
					for (auto &v: tmp) {
						s[v] = '*';
						stk.emplace_back(v);
					}
				}
			}
		}
	}

	cout << ans;

	return 0;
}
