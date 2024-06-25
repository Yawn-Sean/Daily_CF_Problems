#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 1e5 + 10;

int n, q;
long long a[N];
long long s[N];
set <long long> ss;

long long calc(int l, int r) {
	return s[r] - s[l - 1];
}

void work(int st, int ed) {
	long long sum = calc(st, ed);
	ss.insert(sum);
	long long mid = (a[st] + a[ed]) / 2;

	if (a[ed] > mid) {
		int l = st, r = ed;
		while (l + 1 < r) {
			int m = (l + r) >> 1;
			if (a[m] > mid) {
				r = m;
			} else {
				l = m + 1;
			}
		}
		int t = (a[l] > mid) ? l : r;

		work(st, t - 1);
		work(t, ed);
	}
}
		

void solve() {
	scanf("%d%d", &n, &q);

	rep(i, 1, n) scanf("%lld", a + i);
	sort(a + 1, a + n + 1);

	rep(i, 0, n + 2) s[i] = 0;
	rep(i, 1, n) {
		s[i] = s[i - 1] + a[i];
	}

	ss.clear();
	work(1, n);

	while (q--) {
		long long x;
		scanf("%lld", &x);
		puts(ss.count(x) ? "Yes" : "No");
	}

}

int T;


int main() {

	scanf("%d", &T);
	while (T--) {
		solve();
	}

	return 0;
}





