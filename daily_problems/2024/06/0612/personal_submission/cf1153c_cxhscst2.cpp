#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b)	for (int i(a); i <= (b); ++i)
#define dec(i, a, b)	for (int i(a); i >= (b); --i)

const int N = 3e5 + 10;

char s[N];
int n;
int odd = 0;
int cnt = 0;

int main() {

	scanf("%d", &n);
	scanf("%s", s + 1);

	if (n & 1) return 0 * puts(":(");

	rep(i, 1, n) odd += (s[i] == '(');
	if (odd * 2 > n) return 0 * puts(":(");

	rep(i, 1, n) {
		if (s[i] != '?') continue;
		if (odd * 2 < n) {
			++odd;
			s[i] = '(';
		} else {
			s[i] = ')';
		}
	}

	if (odd * 2 < n) return 0 * puts(":(");

	rep(i, 1, n - 1) {
		cnt += (s[i] == '(') ? 1 : -1;
		if (cnt < 0) return 0 * puts(":(");
		if (i & 1) continue;
		if (cnt == 0) return 0 * puts(":(");
	}

	cnt += (s[n] == '(') ? 1 : -1;
	if (cnt == 0) puts(s + 1);
	else puts(":(");
	return 0;
}
