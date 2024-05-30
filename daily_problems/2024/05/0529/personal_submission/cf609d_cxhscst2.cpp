#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;


struct node {
	int x, y;
	long long w;
};

node f[N];
int a[N][2];
int t[N], c[N];
int n, m, k;
int ans = 0;
int p[3];
int l, r;
long long s;

bool check(int idx) {
	long long sum = 0;
	p[1] = p[2] = 1;

	rep(o, 1, 2) {
		rep(i, 2, idx) {
			if (a[i][o] < a[p[o]][o]) {
				p[o] = i;
			}
		}
	}

	rep(i, 1, m) f[i] = {i, p[t[i]], 1ll * c[i] * a[p[t[i]]][t[i]]};

	nth_element(f + 1, f + k, f + m + 1, [](const node &a, const node &b) { return a.w < b.w; });
	rep(i, 1, k) sum += f[i].w;
	return sum <= s;
}

int main() {

	scanf("%d%d%d%lld", &n, &m, &k, &s);

	rep(i, 1, n) scanf("%d", a[i] + 1);
	rep(i, 1, n) scanf("%d", a[i] + 2);
	rep(i, 1, m) scanf("%d%d", t + i, c + i);

	if (!check(n)) return 0 * puts("-1");

	l = 1, r = n;

	while (l + 1 < r) {
		int mid = (l + r) >> 1;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}

	ans = check(l) ? l : r;
	check(ans);

	printf("%d\n", ans);
	rep(i, 1, k) printf("%d %d\n", f[i].x, f[i].y);
	return 0;
}

