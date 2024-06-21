#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;

using ll = long long;
constexpr int P = 1e9 + 7;

ll qpow(ll a, ll b) {
	ll c = 1;
	while(b) {
		if(b & 1) c = c * a % P;
		b >>= 1;
		a = a * a % P;
	}
	return c;
}

ll A, B, x, n;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> B >> n >> x;
	ll t = qpow(A, n % (P - 1));
	ll ans = t * x % P;
	n %= P;
	if(A != 1) {
		t = (t - 1) * qpow(A - 1, P - 2) % P * B % P;
		ans = (ans + t) % P;
	}
	else {
		ans = (ans + B * n) % P;
	}
	cout << ans;
	return 0;
}
