#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1000000007LL;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    if (!(cin >> T)) return 0;


    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int maxA = 0;
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            maxA = max(maxA, a[i]);
        }
        vector<int> freq(maxA + 1, 0);
        for (int v : a) freq[v]++;

        vector<int> mu(maxA + 1, 0), primes;
        vector<int> mind(maxA + 1, 0);
        mu[1] = 1;
        for (int i = 2; i <= maxA; ++i) {
            if (mind[i] == 0) {
                mind[i] = i;
                primes.push_back(i);
                mu[i] = -1;
            }
            for (int p : primes) {
                if (p > mind[i] || (long long)p * i > maxA) break;
                mind[p * i] = p;
                if (p == mind[i]) {
                    mu[p * i] = 0;
                } else {
                    mu[p * i] = -mu[i];
                }
            }
        }
        vector<vector<int>> divisors(maxA + 1);
        for (int d = 1; d <= maxA; ++d) {
            for (int m = d; m <= maxA; m += d) divisors[m].push_back(d);
        }
        vector<int> c(maxA + 1, 0);
        for (int d = 1; d <= maxA; ++d) {
            for (int m = d; m <= maxA; m += d) {
                c[d] += freq[m];
            }
        }
        vector<int> dcnt(maxA + 1, 0);
        for (int v = 1; v <= maxA; ++v) if (freq[v]) {
            for (int m = v; m <= maxA; m += v) dcnt[m] += freq[v];
        }
        vector<ll> A(maxA + 1, 0);
        for (int x = 1; x <= maxA; ++x) {
            ll sum = 0;
            int limit = maxA / x;
            for (int k = 1; k <= limit; ++k) {
                int mu_k = mu[k];
                if (mu_k == 0) continue;
                ll cnt = c[x * k];
                if (cnt < 2 && mu_k != 0) {
                }
                sum += (ll)mu_k * ( (cnt * (cnt - 1)) % MOD );
                if (sum >= (1LL<<62) || sum <= -(1LL<<62)) sum %= MOD; 
            }
            sum %= MOD;
            if (sum < 0) sum += MOD;
            A[x] = sum;
        }

        vector<ll> B(maxA + 1, 0);
        for (int x = 1; x <= maxA; ++x) {
            ll sum = 0;
            for (int e : divisors[x]) {
                int mu_e = mu[e];
                if (mu_e == 0) continue;
                int y = x / e;
                ll cnt = dcnt[y];
                sum += (ll)mu_e * ( (cnt * (cnt - 1)) % MOD );
            }
            sum %= MOD;
            if (sum < 0) sum += MOD;
            B[x] = sum;
        }

        ll ans = 0;
        for (int x = 1; x <= maxA; ++x) {
            if (A[x] == 0 || B[x] == 0) {
            }
            ll cntx = freq[x];
            ll Sx = 0;
            if (cntx > 0) {
                ll t1 = (c[x] - 1);
                ll t2 = (dcnt[x] - 1);
                if (t1 < 0) t1 = 0;
                if (t2 < 0) t2 = 0;
                Sx = ( (cntx % MOD) * (t1 % MOD) ) % MOD;
                Sx = ( Sx * (t2 % MOD) ) % MOD;
            }
            ll overlap = (4 * Sx) % MOD;
            ll sub = ( (2 * ( (cntx % MOD) * ((cntx - 1 + MOD) % MOD) % MOD )) % MOD );
            overlap = (overlap - sub) % MOD;
            if (overlap < 0) overlap += MOD;

            ll prod = (A[x] * B[x]) % MOD;
            ll contrib = (prod - overlap) % MOD;
            if (contrib < 0) contrib += MOD;
            ans += contrib;
            if (ans >= MOD) ans -= MOD;
        }

        cout << ans % MOD << '\n';
    }

    return 0;
}
