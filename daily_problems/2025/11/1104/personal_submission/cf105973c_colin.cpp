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

constexpr int N = 1000007;
constexpr int mod = 998244353;

inline int fpow(int x, int t = mod - 2) {
	int res = 1;
	for (; t; t >>= 1, x = 1ll * x * x % mod)
		if (t & 1) res = 1ll * res * x % mod;
	return res;
}

int fac[N], ifac[N], ans[N];

int main() {
	fac[0] = ifac[0] = 1;
	rep(i, 1, N - 1) fac[i] = 1ll * fac[i - 1] * i % mod;
	ifac[N - 1] = fpow(fac[N - 1]);
	per(i, N - 2, 1) ifac[i] = 1ll * ifac[i + 1] * (i + 1) % mod;
	rep(i, 1, N - 1) {
		ans[i] = 1; 
		if (i % 2 == 0) ans[i] ^= 1ll * fac[i] * ifac[i / 2] % mod * ifac[i / 2] % mod;
	}
	rep(i, 1, N - 1) ans[i] ^= ans[i - 1];
	per(t, rd(), 1) printf("%d\n", ans[rd()]);
	return 0;
}