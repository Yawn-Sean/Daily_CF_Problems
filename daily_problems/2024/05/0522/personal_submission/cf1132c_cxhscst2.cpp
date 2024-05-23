#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)
#define	x				first
#define	y				second

const int N = 5e3 + 10;

int n, m;
int c[N];
int f[3][N];

int mn = 1e9;
int ans = 0;
pair <int, int> a[N];

inline int get(int x, int l, int r) {
	if (l > r) return 0;
	return f[x][r] - f[x][l - 1];
}

int split(int x1, int y1, int x2, int y2) {
	if ((x1 > x2) || (x1 == x2 && y1 > y2)) {
		swap(x1, x2);
		swap(y1, y2);
	}

	int ret = 0;

	if (x2 > y1) {
		ret += get(1, x1, y1);
		ret += get(1, x2, y2);
		return ret;
	}

	if (y1 < y2) {
		ret += get(1, x1, x2 - 1);
		ret += get(1, y1 + 1, y2);
		ret += get(2, x2, y1);
	} else {
		ret += get(1, x1, x2 - 1);
		ret += get(1, y2 + 1, y1);
		ret += get(2, x2, y2);
	}

	return ret;
}


int main() {

	scanf("%d%d", &n, &m);

	rep(i, 1, m) {
		int x, y;
		scanf("%d%d", &x, &y);
		a[i] = {x, y};

		rep(j, x, y) ++c[j];
	}

	rep(i, 1, n) ans += (c[i] > 0);

	rep(i, 1, 2) {
		rep(j, 1, n) f[i][j] += (c[j] == i);
		rep(j, 1, n) f[i][j] += f[i][j - 1];
	}

	rep(i, 1, m - 1) {
		rep(j, i + 1, m) {
			const auto& [x1, y1] = a[i];
			const auto& [x2, y2] = a[j];

			int now = split(x1, y1, x2, y2);
			mn = min(mn, now);
		}
	}

	printf("%d\n", ans - mn);	
	return 0;
}

