#include <bits/stdc++.h>
using namespace std;

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

const double pi = acos(-1);

inline void work() {
	int m = rd(), t = rd();
	double ans = 0;
	if (t < m * 3) {puts("0"); return;}
	int l = 3, r = t / m;
	auto calc = [&](int k) {
		double a = (1.0 * t - k * m) / k;
		return k * a * a / (4.0 * tan(pi / k)); 
	};
	while (r - l >= 5) {
		int lmid = (l + r) / 2 - 1;
		int rmid = lmid + 1;
		if (calc(lmid) <= calc(rmid)) l = lmid;
		else r = rmid;
	}
	rep(i, l, r) ans = max(ans, calc(i));
	printf("%.10lf\n", ans);
}

int main() {
	per(t, rd(), 1) work();
	return 0;
}