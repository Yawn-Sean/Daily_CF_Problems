#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)  for (int i(a); i <= (b); ++i)
#define dec(i, a, b)  for (int i(a); i >= (b); --i)

const int N = 2e5 + 10;

int a[N];
int n;
int c[N];
int ans = 0;
char s[N];

inline int calc(int l, int r) {
	int ret = 0;
	rep(i, l, r) {
		ret = ret * 2 + a[i];
		if (ret > n) {
			return -1;
		}
	}
	return ret;
}

bool check(int l, int r) {	
	return (calc(l, r) == r - l + 1);	
}


void solve() {

	scanf("%s", s + 1);
	n = strlen(s + 1);

	ans = 0;

	rep(i, 1, n) a[i] = (s[i] == '1');
	rep(i, 0, n + 2) c[i] = a[i];
	rep(i, 1, n) c[i] += c[i - 1];

	rep(i, 1, n) {
		rep(j, max(1, i - 20), i) {
			ans += (check(j, i) == true);
		}
	}
	
	rep(i, 22, n) {
		int p = i - 21;
		int now = calc(p, i);
		if (now <= 0) continue;

		int st = i - now + 1;
		if (st < 1 || st > p) {
			continue;
		}

		if (c[p - 1] == c[st - 1]) {
			++ans;
		}
	}

	printf("%d\n", ans);
}

int T;

int main() {

	scanf("%d", &T);

	while (T--) {
		solve();
	}


	return 0;
}

