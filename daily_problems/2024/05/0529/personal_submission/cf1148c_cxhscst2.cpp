#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 3e5 + 10;

int n;
int a[N];
int p[N];
int cnt = 0;
pair <int, int> ans[N * 5];

void work(int x, int y) {
	int nx = a[x], ny = a[y];
	swap(a[x], a[y]);
	swap(p[nx], p[ny]);
	ans[++cnt] = {x, y};
}

int main() {

	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", a + i);
	rep(i, 1, n) p[a[i]] = i;

	if (a[1] != 1) {
		if (p[1] > n / 2) {
			work(1, p[1]);
		} else {
			work(p[1], n);
			work(1, n);
		}
	}

	rep(i, 2, n / 2) {
		int pi = p[i];
		if (pi == i) {
			continue;
		}

		if (abs(pi - i) >= n / 2) {
			work(i, pi);
			continue;
		}

		if (pi <= n / 2) {
			work(pi, n);
			work(i, n);
			continue;
		}

		work(pi, 1);
		work(1, n);
		work(i, n);
		work(1, pi);
	}

	rep(i, n / 2 + 1, n) {
		int pi = p[i];
		if (pi == i) continue;

		work(pi, 1);
		work(1, i);
		work(pi, 1);
	}

	printf("%d\n", cnt);
	rep(i, 1, cnt) printf("%d %d\n", ans[i].first, ans[i].second);
	return 0;
}

