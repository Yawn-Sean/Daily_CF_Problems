#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;
namespace rgs = ranges;

constexpr int N = 3e6;
constexpr int md = 998244353;

i64 qpow(i64 a, i64 b) {
	i64 ans = 1;
	a %= md;
	while (b) {
		if (b & 1) {
			ans = ans * a % md;
		}
		a = a * a % md;
		b >>= 1;
	}
	return ans;
}

vector<i64> F(N + 1), invF(N + 1);
void init() {
	F[0] = 1;
	for (int i = 1; i <= N; i++) {
		F[i] = F[i - 1] * i % md;
	}
	invF[N] = qpow(F[N], md - 2);
	for (int i = N - 1; i >= 0; i--) {
		invF[i] = invF[i + 1] * (i + 1) % md;
	}
}

i64 A(i64 a, i64 b) {
	if (a < 0 || b < 0 || b > a) {
		return 0;
	}
	return F[a] * invF[a - b] % md;
}
i64 C(i64 a, i64 b) {
	if (a < 0 || b < 0 || b > a) {
		return 0;
	}
	return F[a] * invF[b] % md * invF[a - b] % md;
}

void add(i64& a, i64 b) {
	a += b;
	if (a >= md) {
		a -= md;
	}
}

void solve() {
	i64 a, b, c, d;
	cin >> a >> b >> c >> d;
	i64 od = (a + b + c + d + 1) / 2, ev = (a + b + c + d) / 2;
	if (a + d != od) {
		cout << 0 << "\n";
		return;
	}

	cout << C(od - 2, a - 2) * C(ev, b) % md << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	init();
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}