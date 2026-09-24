#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

const int N = 5003;
long long fact[N], infact[N];

long long qmi(long long a,long long b,long long p) {
	long long ans = 1;
	while (b) {
		if (b & 1) ans = ans * a % p;
		b >>= 1;
		a = a * a % p;
	}
	return ans % p;
}

void init() {
	fact[0] = infact[0] = 1;
	for (int i = 1; i < N; i++) {
		fact[i] = fact[i - 1] * i % mod;
	}
	infact[N - 1] = qmi(fact[N - 1], mod - 2, mod);
	for (int i = N - 2; i >= 1; i--) {
		infact[i] = infact[i + 1] * (i + 1) % mod;
	}
}

long long C(int n, int m) {
	if (n < m) return 0;
	return fact[n] * infact[m] % mod * infact[n - m] % mod;
}

struct node {
	int x, y;
	bool operator < (const node& e2) const {
		if (x != e2.x) return x < e2.x;
		return y < e2.y;
	}
};

void soviet() {
	init();
	int n, k; std::cin >> n >> k;
	std::vector<node> a(n + 1);
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].x;
	}
	for (int i = 1; i <= n; i++) {
		std::cin >> a[i].y;
	}

	if (k == 1) {
		cout << 0;
		return;
	}

	std::sort(a.begin() + 1, a.end());

	long long ans = C(n, k);
	for (int i = 1; i <= n; i++) {
		int now = 0;
		for (int j = 1; j < i; j++) {
			if (a[i].x > a[j].x && a[i].y > a[j].y) now++;
		}
		ans = (ans - C(now, k - 1) + mod) % mod;
	}
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}
