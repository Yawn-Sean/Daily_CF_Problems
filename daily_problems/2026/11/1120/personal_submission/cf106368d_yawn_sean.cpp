#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;

	int n = t / 2, cur = 0;
	vector<int> timestamps(n + 1), stk;

	for (int i = 1; i <= t; i ++) {
		char op; int x;
		cin >> op >> x;

		vector<pair<int, int>> ops;

		if (op == '+') timestamps[++cur] = x;
		else ops.emplace_back(2, stk.back()), stk.pop_back();

		int w = 2 * (i & -i) - 1;

		vector<int> tmp;
		if (op == '+') tmp.emplace_back(cur);

		while (w && !stk.empty()) {
			w --;
			int u = stk.back();
			ops.emplace_back(2, u);
			tmp.emplace_back(u);
			stk.pop_back();
		}

		sort(tmp.begin(), tmp.end(), [&] (int i, int j) {return timestamps[i] > timestamps[j];});

		for (auto &x: tmp) {
			ops.emplace_back(1, x);
			stk.emplace_back(x);
		}

		cout << ops.size() << '\n';
		for (auto &[t, x]: ops) cout << t << ' ' << x << '\n';
		cout.flush();
	}

	return 0;
}