#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;

int n;
int cnt = 0;
int ans[N];
int p = 0, q = 0;
bool c[N];
vector <int> v[N];

void dfs(int x) {
	c[x] = true;
	ans[++cnt] = x;

	for (auto u : v[x]) {
		if (c[u]) {
			continue;
		}
		dfs(u);
	}
}


int main() {

	scanf("%d", &n);

	rep(i, 1, n) {
		int x, y;
		scanf("%d%d", &x, &y);
		if (i == 1) {
			p = x;
			q = y;
		}
		v[x].emplace_back(y);
		v[y].emplace_back(x);
	}
	
	c[1] = true;
	dfs(1);

	if (ans[n] == p || ans[n - 1] == p) {
		dec(i, n, 1) printf("%d ", ans[i]);
	} else {
		rep(i, 1, n) printf("%d ", ans[i]);
	}
	putchar(10);	
	return 0;
}

