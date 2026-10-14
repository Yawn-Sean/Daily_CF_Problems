#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<long long> res(n + 1, 0);
	vector<int> vis(n + 1, 0);

	pair<int, int> next_query = {-1, -1};

	auto query = [&] (int x, int y) -> long long {
		next_query = {-1, -1};
		cout << "? " << x << ' ' << y << endl;

		long long s; int vx, vy;
		cin >> s >> vx >> vy;

		if (!vis[vy]) {
			if (vx == vy) next_query = {1, vy};
			if (vx == 1) next_query = {vy, vy};
		}

		return s;
	};

	res[1] = query(1, 1);
	vis[1] = 1;

	int pt = 1;

	for (int i = 0; i < n - 1; i ++) {
		if (next_query.first != -1) {
			auto [x, y] = next_query;
			if (x == 1) vis[y] = 1;
			else vis[y] = 2;
			res[y] = query(x, y);
		}
		else {
			while (vis[pt]) pt ++;
			vis[pt] = 2;
			res[pt] = query(pt, pt);
		}
	}

	cout << "!\n";
	cout << res[1];
	
	long long cur = res[1];

	for (int i = 2; i <= n; i ++) {
		if (vis[i] == 2) {
			cout << ' ' << res[i];
			cur += res[i];
		}
		else {
			cout << ' ' << res[i] - cur;
			cur = res[i];
		}
	}

	return 0;
}