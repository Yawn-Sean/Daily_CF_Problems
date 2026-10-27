#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t, inf = 2e9;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		int mnx = inf, mxx = -inf;
		int mny = inf, mxy = -inf;

		vector<pair<int, int>> pts(n);

		for (auto &[x, y]: pts) {
			cin >> x >> y;
			mnx = min(mnx, x), mxx = max(mxx, x);
			mny = min(mny, y), mxy = max(mxy, y);
		}

		auto check = [&] (int vx, int vy) -> bool {
			for (auto &[x, y]: pts) {
				if (x == vx && y == vy) {
					return true;
				}
			}
			return false;
		};

		if (check(mnx, mny) && check(mnx, mxy) && check(mxx, mny) && check(mxx, mxy)) cout << "YES\n";
		else cout << "NO\n";
	}

	return 0;
}