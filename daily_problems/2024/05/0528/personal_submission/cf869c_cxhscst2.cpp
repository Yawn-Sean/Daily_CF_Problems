#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 5010;
const int mod = 998244353;

int P[N][N], C[N][N];
int a, b, c;

int calc(int x, int y) {
	if (x > y) swap(x, y);
	int ret = 0;
	rep(i, 0, x) ret = (ret + 1ll * P[y][i] * C[x][i]) % mod;
	return ret;
}


int main() {

	C[0][0] = P[0][0] = 1;
	scanf("%d%d%d", &a, &b, &c);

	rep(i, 1, 5000) {
		C[i][0] = P[i][0] = 1;
		rep(j, 1, i){
			P[i][j] = (1ll * P[i - 1][j - 1] * j % mod + 1ll * P[i - 1][j] % mod) % mod;
			C[i][j] = (1ll * C[i - 1][j - 1] + 1ll * C[i - 1][j]) % mod;
		}
	}

	rep(i, 1, 6) {
		rep(j, 1, i) printf("%d ", P[i][j]);
		putchar(10);
	}

	int ans = 1ll * calc(a, b) % mod * 1ll * calc(b, c) % mod * 1ll * calc(a, c) % mod;
	printf("%d\n", ans);
	return 0;
}


