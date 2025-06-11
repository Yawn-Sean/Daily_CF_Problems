#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;

int n;
int a[N], b[N], c[N], f[N], ans[N];
bool v[N];

int query(int x) {
	int ret = 0;
	for (; x; x -= x & -x) {
		ret += c[x];
	}
	return ret;
}

void update(int x, int val) {
	for (; x <= n; x += x & -x) {
		c[x] += val;
	}
}

void calc(int* a) {
	memset(c, 0, sizeof c);
	dec(i, n, 1) {
		f[n - i] += query(a[i]);
		update(a[i] + 1, 1);
	}
}

int main() {

	scanf("%d", &n);

	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) scanf("%d", b + i);

	calc(a);
	calc(b);

	rep(i, 1, n - 1) {
		if (f[i] >= i + 1) {
			int cnt = f[i] / (i + 1);
			f[i + 1] += cnt;
			f[i] %= (i + 1);
		}
	}

	memset(c, 0, sizeof c);

	rep(i, 1, n) {
		int l = 1, r = n;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (mid - query(mid) >= f[n - i] + 1) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}

		int t = l - query(l) >= f[n - i] + 1 ? l : r;
		update(t, 1);
		ans[i] = t - 1;
	}

	rep(i, 1, n) printf("%d ", ans[i]);
	return 0;
}

