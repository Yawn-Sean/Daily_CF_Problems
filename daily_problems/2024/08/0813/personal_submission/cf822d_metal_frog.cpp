#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
 
using ull = unsigned long long;
using ll = long long;
using pii = pair<int, int>;

const int N = 5e6 + 7;
const ll mod = 1e9 + 7;

int firstPrime[N];
ll F[N];
void sieve() {
	for (int i = 4; i < N; i += 2) firstPrime[i] = 2;
	for (int i = 3; i*i < N; i += 2) if (firstPrime[i] == 0)
		for (int j = i*i; j < N; j += i*2) {
            if (firstPrime[j] == 0) firstPrime[j] = i;
        }
}

ll modpow(ll b, ll e) {
	ll ans = 1;
	for (; e; b = b * b % mod, e /= 2)
		if (e & 1) ans = ans * b % mod;
	return ans;
}

void solve() {
    sieve();     
    int t, L, R;
    cin >> t >> L >> R;

    F[1] = 1;
    for (int i = 2; i < N; i++) {
        if (firstPrime[i] == 0) {
            F[i] = ll(i) * ll(i - 1) / 2LL;
            F[i] %= mod;
        } else {
            F[i] = ll(i) * (firstPrime[i] - 1LL) / 2LL;
            F[i] += F[i / firstPrime[i]];
            F[i] %= mod;
        }
    }
    ll ans = 0;
    for (int i = L; i <= R; i++) {
        ll x = modpow(t, i - L);
        ans += (x * F[i]) % mod;
        ans %= mod;
    }
    cout << ans << "\n";
}
 
int main() {
    cin.tie(0)->sync_with_stdio(0);
    cin.exceptions(cin.failbit);
    solve();
}
