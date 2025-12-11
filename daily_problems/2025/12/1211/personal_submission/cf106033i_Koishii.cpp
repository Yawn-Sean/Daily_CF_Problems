#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
const int N = 2000006;

long long qmi(long long a,long long b,long long p){
	long long ans = 1;
	while(b){
		if(b&1) ans = ans*a%p;
		b>>=1;
		a = a*a%p;
	}
	return ans%p;
}

long long fact[N], infact[N];
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

long long C(int a, int b) {
	if (a < b) return 0;
	return fact[a] * infact[b] % mod * infact[a - b] % mod;
}

void soviet() {
	init();
	int n, k; std::cin >> n >> k;
	n--;
	long long ans = 0;
	for (int i = n - k - 1; i <= n + k; i++) {
		ans = (ans + C(2 * n, i)) % mod;
	}
	std::cout << ans;
}

int main() {
	int M_T = 1; std::ios::sync_with_stdio(false); std::cin.tie(nullptr);
//	std::cin >> M_T;
	while (M_T--) { soviet(); }
	return 0;
}