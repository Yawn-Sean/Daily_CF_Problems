#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 3e5 + 10;

char s[N];
int n;
int a[N];
int c[N];
int cnt = 0;
long long ans = 0;

int main() {

	scanf("%s", s + 1);
	n = strlen(s + 1);

	rep(i, 1, n) {
		c[i] = n + 1;
	}

	rep(i, 2, n - 1) {
		rep(l, 1, n) {
			int j = i - l, k = i + l;
			if (j < 1 || k > n) break;
			if (s[i] == s[j] && s[i] == s[k]) {
				c[j] = min(c[j], k);
				break;
			}
		}
	}

	dec(i, n - 1, 1) {
		c[i] = min(c[i], c[i + 1]);
		if (c[i] <= n) {
			ans += 1ll * (n - c[i] + 1);
		}
	}

	printf("%lld\n", ans);
	return 0;
}


