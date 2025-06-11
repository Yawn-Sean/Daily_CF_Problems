#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<array>
using namespace std;
typedef pair<int, int> pii;
int main() {
	int n, tx, ty, tz;
	cin >> n >> tx >> ty >> tz;
	tx--; ty--; tz--;
	auto fix = [&](int& x, int& y, int& z)->void {
		if (x > y) swap(x, y);
		if (y > z) swap(y, z);
		if (x > y) swap(x, y);
	};
	auto f = [&](int x, int y, int z)->int {
		return (x * n + y) * n + z;
	};
	fix(tx, ty, tz);
	vector<string>g(n);
	for (auto& s : g) cin >> s;
	queue<array<int, 3>>q;
	vector<int>pre(n * n * n, -2);
	vector<pii>path(n * n * n);
	pre[f(0, 1, 2)] = -1;
	q.push({ 0,1,2 });
	while (!q.empty()) {
		auto p = q.front(); q.pop();
		int x = p[0], y = p[1], z = p[2];
		for (int nx = 0; nx < n; nx++) {
			if (nx == x || nx == y || nx == z) continue;
			if (g[x][nx] == g[y][z]) {
				int a = nx, b = y, c = z;
				fix(a, b, c);
				int nf = f(a, b, c);
				if (pre[nf] == -2) {
					pre[nf] = f(x, y, z);
					path[nf] = { nx + 1,x + 1 };
					q.push({ a,b,c });
				}
			}
		}

		for (int ny = 0; ny < n; ny++) {
			if (ny == x || ny == y || ny == z) continue;
			if (g[y][ny] == g[x][z]) {
				int a = x, b = ny, c = z;
				fix(a, b, c);
				int nf = f(a, b, c);
				if (pre[nf] == -2) {
					pre[nf] = f(x, y, z);
					path[nf] = { ny + 1,y + 1 };
					q.push({ a,b,c });
				}
			}
		}

		for (int nz = 0; nz < n; nz++) {
			if (nz == x || nz == y || nz == z) continue;
			if (g[z][nz] == g[x][y]) {
				int a = x, b = y, c = nz;
				fix(a, b, c);
				int nf = f(a, b, c);
				if (pre[nf] == -2) {
					pre[nf] = f(x, y, z);
					path[nf] = { nz + 1,z + 1 };
					q.push({ a,b,c });
				}
			}
		}
	}

	int nf = f(tx, ty, tz);
	if (pre[nf] == -2) cout << -1;
	else {
		vector<pii>ans;
		while (nf != f(0, 1, 2)) {
			ans.push_back(path[nf]);
			nf = pre[nf];
		}
		cout << ans.size() << endl;
		for (auto& p : ans)
			cout << p.first << " " << p.second << endl;
	}
	return 0;
}
