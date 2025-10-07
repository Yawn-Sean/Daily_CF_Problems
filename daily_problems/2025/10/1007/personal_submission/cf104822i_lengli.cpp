#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int MAXP = 40000;
    vector<int> is_prime(MAXP + 1, 1), primes;

    for (int i = 2; i <= MAXP; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
            for (int j = i * 2; j <= MAXP; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    int t;
    cin >> t;
    while (t--) {
        int a;
        cin >> a;

        map<int, int> prime_exp;
        int val = a;
        for (auto p : primes) {
            if (1LL * p * p > val) break;
            while (val % p == 0) {
                prime_exp[p]++;
                val /= p;
            }
        }
        if (val > 1) prime_exp[val]++;

        vector<int> factors = {1};
        for (auto [p, cnt] : prime_exp) {
            int cur_size = factors.size();
            for (int i = 0; i < cnt * cur_size; i++) {
                factors.push_back(factors[i] * p);
            }
        }

        sort(factors.begin(), factors.end());

        long long ans = 1LL * a * a;
        for (int i = 0; i + 1 < (int)factors.size(); i++) {
            int val = factors[i] * factors[factors.size() - 2 - i];
            ans = min(ans, 1LL * a * a / val - a);
        }
        cout << ans << '\n';
    }

    return 0;
}
