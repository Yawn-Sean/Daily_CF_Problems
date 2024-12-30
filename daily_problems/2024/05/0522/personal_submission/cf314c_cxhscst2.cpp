#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 1e6 + 10;

const long long mod = 1e9 + 7;

int n;
int a[N];
int mx = 0;
long long ans = 0;
long long c[N], f[N];

inline void up(long long& x, long long y) {
	x += y;
	x %= mod;
}

inline void mul(long long& x, long long y) {
	x *= y;
	x %= mod;
}

long long query(int x) {
	long long ret = 0;
	for (; x; x -= x & -x) {
		up(ret, c[x]);
	}
	return ret;
}

void update(int x, long long val) {
	for (; x <= mx; x += x & -x) {
		up(c[x], val);
	}
}

int main() {

	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) mx = max(mx, a[i]);

	rep(i, 1, n) {
		long long cnt = query(a[i]);
		up(cnt, 1);
		mul(cnt, a[i]);

		update(a[i], mod - f[a[i]]);
		update(a[i], cnt);
		f[a[i]] = cnt;
	}

	rep(i, 1, mx) {
		up(ans, f[i]);
	}

	printf("%lld\n", ans);	
	return 0;
}

