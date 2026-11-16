#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> gs(1 << n), ms(1 << n);
	for (auto &g: gs) cin >> g;
	for (auto &m: ms) cin >> m;

	int inf = 1e9;

	auto dfs = [&] (auto &self, int l, int r) -> vector<array<long long, 4>> {
		if (l == r) return {{0, inf, l, 0}};

		int mid = (l + r) / 2;
		auto vl = self(self, l, mid);
		auto vr = self(self, mid + 1, r);

		int pl = 0, pr = 0;

		vector<array<long long, 4>> ans;

		while (pl < vl.size() && pr < vr.size()) {
			auto [dl1, dr1, win1, score1] = vl[pl];
			auto [dl2, dr2, win2, score2] = vr[pr];

			int dl = max(dl1, dl2);
			int dr = min(dr1, dr2);

			if (dl <= dr) {
				long long score = score1 + score2 + ms[win1] + ms[win2];
			
				if (gs[win1] > gs[win2]) {
					int sep = gs[win1] - gs[win2];
					if (sep >= dl && sep <= dr) ans.push_back({dl, sep, win1, score});
					if (sep + 1 >= dl && sep + 1 <= dr) ans.push_back({sep +  1, dr, win2, score});
					if (sep > dr) ans.push_back({dl, dr, win1, score});
					if (sep + 1 < dl) ans.push_back({dl, dr, win2, score});
				}
				else {
					int sep = gs[win2] - gs[win1];
					if (sep >= dl && sep <= dr) ans.push_back({dl, sep, win2, score});
					if (sep + 1 >= dl && sep + 1 <= dr) ans.push_back({sep +  1, dr, win1, score});
					if (sep > dr) ans.push_back({dl, dr, win2, score});
					if (sep + 1 < dl) ans.push_back({dl, dr, win1, score});
				}
			}

			if (dr1 < dr2) pl ++;
			else pr ++;
		}

		return ans;
	};

	long long ans = -1;
	int chosen = -1;

	for (auto &[dl, dr, win, score]: dfs(dfs, 0, (1 << n) - 1)) {
		if (score > ans) {
			ans = score;
			chosen = dl;
		}
	}

	cout << ans << '\n' << chosen;

	return 0;
}