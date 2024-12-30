#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)  for (int i(a); i <= (b); ++i)
#define dec(i, a, b)  for (int i(a); i >= (b); --i)

const int mod = 1e9 + 7;
const int N = 1e3 + 10;

int f[N][N];
int n, k;

void solve() {
	scanf("%d%d", &n, &k);

	rep(i, 1, n) f[1][i] = 1;
	rep(i, 1, k) f[i][0] = 1;

	rep(i, 1, k) {
		rep(j, 1, n) {
			f[i][j] = (f[i][j - 1] + f[i - 1][n - j]) % mod;
		}
	}

	printf("%d\n", f[k][n]);
}

int T;

int main() {

	scanf("%d", &T);

	while (T--) {
		solve();
	}

	return 0;
}


