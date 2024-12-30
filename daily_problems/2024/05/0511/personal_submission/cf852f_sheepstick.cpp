#include<bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 quickP(i64 a, i64 b, i64 p) {
	i64 res = 1;
	while(b){
		if (b & 1) res = res * a % p;
		a = a * a % p;
		b >>= 1;
	}

	return res;
};

void solve() {
    i64 n, m, a, q; cin >> n >> m >> a >> q;

    auto phi = [&](i64 a, i64 q) -> i64 {
    	i64 res = 0, i = 1;
    	while(i != 1 || res == 0){
    		i = i * a % q;
    		res++;
    	}
    	return res;
    };

    int mod = phi(a, q);
    vector<i64> fac(m + 1), invfac(m + 1);
    fac[0] = invfac[0] = 1;

    for (int i = 1; i <= m; i++){
    	fac[i] = fac[i - 1] * i % mod;
    }
    invfac[m] = quickP(fac[m], mod - 2, mod);
    for (int i = m; i > 0; i--){
    	invfac[i - 1] = invfac[i] * i % mod;
    }


    auto binom = [&](int a, int b) -> i64 {
    	if (a < b || b < 0) return 0;
    	return fac[a] * invfac[b] % mod * invfac[a - b] % mod;
    };
    i64 cur = 0;
    vector<i64> res(n, 0);
    for (int i = 0; i < n; i++){
    	cur = (cur + binom(m, i)) % mod;
    	res[n - 1 - i] = quickP(a, cur, q);
    }
    for (int i = 0; i < n; i++){
    	cout << res[i] << " \n"[i == n - 1];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int t = 1;
    //std::cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}