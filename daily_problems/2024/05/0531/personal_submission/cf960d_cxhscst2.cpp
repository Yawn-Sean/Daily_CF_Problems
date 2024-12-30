#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define	dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 105;

long long delta[N], c[N], l[N], r[N];
long long la, now, x, k;
int cnt = 0;
int q, op;

void out(long long a) {
	if (a >= 10) out(a / 10);
	putchar(a % 10 + '0');
}

int calc(long long x) {
	int ret = 0;
	for (; x; x >>= 1ll) ++ret;
	return ret;
}

int main() {

	now = 0;
	la = now + 1;
	rep(i, 0, 62) {
		now += 1ll << i;
		l[++cnt] = la, r[cnt] = now;
		c[cnt] = 1ll << i;
		la = now + 1;
	}

	scanf("%d", &q);
	while (q--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%lld%lld", &x, &k);
			int et = calc(x);

			k %= c[et];
			k += c[et];
			k %= c[et];

			delta[et] += k;
			delta[et] %= c[et];
		}

		else if (op == 2) {
			scanf("%lld%lld", &x, &k);
			int et = calc(x);

			k %= c[et];
			k += c[et];
			k %= c[et];

			rep(i, et, 61) {
				k %= c[i];
				delta[i] += k;
				delta[i] %= c[i];
				k = k * 2ll;
			}
		}

		else {
			scanf("%lld", &x);
			out(x);
			int et = calc(x);

			long long pos = x - l[et];
			pos = pos + delta[et];
			pos %= c[et];

			dec(i, et - 1, 1) {
				pos >>= 1ll;
				long long re = pos;
				re = re - delta[i];
				re = re + c[i];
				re %= c[i];
				re += l[i];
				putchar(32);
				out(re);
			}

			putchar(10);
		}

	}

	return 0;
}



