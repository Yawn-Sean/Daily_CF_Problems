#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;

int sqt[N];
int n;
int mod;
int pre = 0;
int f[N];

inline void up(int &x, int y) {
	x += y;
	if (x >= mod) {
		x -= mod;
	}
}

inline int nxt(int x, int now) {
	if (x <= now) {
		return -1;
	}
 
	if (now < sqt[x]) {
		return now + 1;
	}
 
	int g = x / now - 1;
	while (x / g <= now) --g;
	return x / g;
}

int main() {

	scanf("%d%d", &n, &mod);
	
	rep(i, 2, 2e5) sqt[i] = (int)sqrt(i);

	f[n] = 1;

	dec(i, n, 2) {
		int cnt = 1;
		int ed = i;

		up(f[i], pre);

		while (cnt < i) {
			int l = 1, r = ed;

			while (l + 1 < r) {
				int mid = (l + r) >> 1;
				if (i / mid == cnt) {
					r = mid;
				} else {
					l = mid + 1;
				}
			}

			int t = (i / l == cnt) ? l : r;
			int num = 1ll * (ed - t + 1) * f[i] % mod;
			up(f[cnt], num);
			ed = t - 1;
			cnt = nxt(i, cnt);
		}

		up(pre, f[i]);
	}

	up(f[1], pre);
	printf("%d\n", f[1]);
	return 0;
}





