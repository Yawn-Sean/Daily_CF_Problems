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

constexpr int mod = 1000000007;

vector<int> fac;

inline void work() {
	int n = rd();
	vector<int> x, y, X, Y;
	rep(i, 1, (n << 1)) x.eb(rd()), y.eb(rd());
	X = x; sort(all(x));
	Y = y; sort(all(y));
	if (x[n] == x[n - 1] || y[n] == y[n - 1]) {
		puts("0"); return;
	}
	int num = 0;
	rep(i, 0, (n << 1) - 1) 
		num += (X[i] <= x[n - 1] && Y[i] <= y[n - 1]);
	printf("%d\n", 1ll * fac[num] * fac[n - num] % mod);
}

int main() {
	fac.eb(1);
	rep(i, 1, 100000) fac.eb(1ll * fac.back() * i % mod);
	per(t, rd(), 1) work();
	return 0;
}