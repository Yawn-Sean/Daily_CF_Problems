#include <bits/stdc++.h>

using namespace std;
constexpr int MX = 1000003;
constexpr int N = 200003;
int ls[MX];
int rs[MX];
int a[N];
int p[N];

int main() {
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1, x; i <= n; i++) {
		scanf("%d", &x);
		a[i] = x;
		if (ls[x] == 0) {
			ls[x] = i;
			rs[x] = i;
			p[i] = i - 1;
		} else {
			if (rs[x] + 1 == i) {
				rs[x] += 1;
				p[i] = ls[x] - 1;
			} else {
				ls[x] = i;
				rs[x] = i;
				p[i] = i - 1;
			}
		}
	}
	for (int i = 0, l, r, x; i < m; i++) {
		scanf("%d%d%d", &l, &r, &x);
		if (a[r] != x) {
			printf("%d\n", r);
		} else {
			if (p[r] >= l) {
				printf("%d\n", p[r]);
			} else {
				printf("-1\n");
			}
		}
	}
	return 0;
}

