#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int rd() {
	int x = 0;
	bool f = 0;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) f |= (c == '-');
	for (; isdigit(c); c = getchar()) x = x * 10 + (c ^ 48);
	return f ? -x : x;
}

#define eb emplace_back
#define all(s) (s).begin(), (s).end()
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define per(i, a, b) for (int i = (a); i >= (b); --i)

constexpr int N = 100007;

int a[N], b[N];

int main() {
	int n = rd();
	rep(i, 1, n) a[i] = rd();
	b[1] = a[1];
	ll ans1 = 0, ans2 = 0;
	rep(i, 2, n) {
		if (i & 1) {
			int dlt = max(0, b[i - 1] + 1 - a[i]);
			ans1 += dlt;
			b[i] = a[i] + dlt;
		} else {
			int dlt = max(0, a[i] - b[i - 1] + 1);
			ans1 += dlt;
			b[i] = a[i] - dlt;
		}
	}
	rep(i, 2, n) {
		if (i & 1) {
			int dlt = max(0, a[i] - b[i - 1] + 1);
			ans2 += dlt;
			b[i] = a[i] - dlt;
		} else {
			int dlt = max(0, b[i - 1] + 1 - a[i]);
			ans2 += dlt;
			b[i] = a[i] + dlt;
		}
	}
	printf("%lld\n", min(ans1, ans2));
	return 0;
}