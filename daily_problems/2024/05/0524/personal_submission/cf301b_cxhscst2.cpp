#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 105;

int n, d;
int a[N];
int x[N], y[N];
int f[N][N];

int main() {

	scanf("%d%d", &n, &d);
	rep(i, 2, n - 1) scanf("%d", a + i);
	rep(i, 1, n) scanf("%d%d", x + i, y + i);

	rep(i, 1, n) {
		rep(j, 1, n) {
			if (i == j) {
				continue;
			}
			f[i][j] = (abs(x[i] - x[j]) + abs(y[i] - y[j])) * d - a[j];
		}
	}

	rep(k, 1, n) {
		rep(i, 1, n) {
			rep(j, 1, n) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}

	printf("%d\n", f[1][n]);
	return 0;
}

