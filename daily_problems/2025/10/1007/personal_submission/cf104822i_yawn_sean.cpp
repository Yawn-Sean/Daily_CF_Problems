#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int M = 40000;
    vector<int> isPrime(M + 1, 1), primes;

    for (int i = 2; i <= M; i ++) {
        if (isPrime[i]) {
            primes.emplace_back(i);
            for (int j = i * 2; j <= M; j += i) {
                isPrime[j] = 0;
            }
        }
    }

    int t;
    cin >> t;

    while (t --) {
        int a;
        cin >> a;

        map<int, int> prs;

        int va = a;
        for (auto &pr: primes) {
            if (pr * pr > va) break;
            while (va % pr == 0) {
                prs[pr] ++;
                va /= pr;
            }
        }

        if (va > 1) prs[va] ++;

        vector<int> factors = {1};

        for (auto &[p, x]: prs) {
            int c = x * factors.size();

            for (int i = 0; i < c; i ++) {
                factors.emplace_back(factors[i] * p);
            }
        }

        sort(factors.begin(), factors.end());

        long long ans = 1ll * a * a;

        for (int i = 0; i < factors.size() - 1; i ++) {
            int val = factors[i] * factors[factors.size() - 2 - i];
            ans = min(ans, 1ll * a * a / val - a);
        }

        cout << ans << '\n';
    }

    return 0;
}