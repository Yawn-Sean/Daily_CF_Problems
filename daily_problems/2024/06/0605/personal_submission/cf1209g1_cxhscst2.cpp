#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;


int n, q;
int a[N];
int c[N];
int last_pos[N];
int x;
int ans = 0;

int main() {

	scanf("%d%d", &n, &q);

	rep(i, 1, n) {
		scanf("%d", a + i);
		last_pos[a[i]] = i;
	}

	x = 1;
	while (x <= n) {
		int ed = last_pos[a[x]];
		
		rep(i, x, ed) {
			ed = max(ed, last_pos[a[i]]);
		}

		int mx = 0;
		rep(i, x, ed) {
			++c[a[i]];
			mx = max(mx, c[a[i]]);
		}

		ans += (ed - x + 1 - mx);

		rep(i, x, ed) {
			c[a[i]] = 0;
		}

		x = ed + 1;
	}

	printf("%d\n", ans);
	return 0;
}

