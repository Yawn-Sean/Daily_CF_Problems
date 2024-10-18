#include <bits/stdc++.h>

using namespace std;

#define	rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)
#define	x				first
#define	y				second

const int N = 2e3 + 10;

double num;
int n;
int a[N << 1];
int cnt = 0;
int s = 0;
int ans;
int len, pos, v;
char st[20];


int main() {

	scanf("%d", &n);
	rep(i, 1, 2 * n) {
		scanf("%s", st + 1);
		len = strlen(st + 1);
		pos = 0;
		rep(j, 1, len) {
			if (st[j] == '.') {
				pos = j;
				break;
			}
		}

		rep(j, pos + 1, pos + 3) {
			v = st[j] - '0';
			a[i] = a[i] * 10 + v;
		}

		cnt += (a[i] == 0);
		s += a[i];
	}

	ans = 2e9;

	rep(i, max(0, n - cnt), min(n, 2 * n - cnt)) {
		ans = min(ans, abs(s - i * 1000));
	}

	printf("%.3f\n", 0.001 * ans);
	return 0;
}


