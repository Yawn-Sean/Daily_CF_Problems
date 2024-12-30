#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)
#define	x				first
#define	y				second

const int N = 2e3 + 10;

int n;
int c[N];
int rt = 0;
int sz[N];
int a[N];
vector <int> v[N];

void pre_dfs(int x, int fa) {
	sz[x] = 1;

	for (auto u : v[x]) {
		pre_dfs(u, x);
		sz[x] += sz[u];
	}

}

void dfs(int x, int fa) {
	bool has_son = false;

	for (auto u : v[x]) {
		has_son = true;
		dfs(u, x);
	}

	if (!has_son) {
		a[x] = 1;
		return;
	}

	vector < pair <int, int> > f;

	queue <int> q;

	q.push(x);
	while (!q.empty()) {
		int u = q.front();
		q.pop();

		if (u ^ x) {
			f.emplace_back(a[u], u);
		}

		for (auto w : v[u]) {
			q.push(w);
		}
	}

	sort(f.begin(), f.end());

	int now_sz = (int)f.size();

	if (c[x] == 0) {
		a[x] = 1;
		if (f.front().x == 1) {
			for (const auto& [val, idx] : f) {
				a[idx] = val + 1;
			}
		}

		return;
	}
			
	if (c[x] >= now_sz) {
		a[x] = f.back().x + 1;
		return;
	}

	rep(i, c[x], now_sz - 1) {
		const auto [val, idx] = f[i];
		a[idx] = val + 2;
	}
	
	a[x] = f[c[x] - 1].x + 1;
}


int main() {

	scanf("%d", &n);

	rep(i, 1, n) {
		int x;
		scanf("%d%d", &x, c + i);
		if (x == 0) {
			rt = i;
		} else {
			v[x].emplace_back(i);
		}
	}

	pre_dfs(rt, 0);

	rep(i, 1, n) {
		if (c[i] > sz[i] - 1) {
			return 0 * puts("NO");
		}
	}

	dfs(rt, 0);

	puts("YES");
	rep(i, 1, n) printf("%d\n", a[i]);
	return 0;
}





