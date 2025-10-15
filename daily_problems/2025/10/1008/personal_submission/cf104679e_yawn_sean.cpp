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

    int M = 1e7;

    vector<int> is_prime(M + 1, 1);
    is_prime[0] = 0, is_prime[1] = 0;

    for (int i = 2; i <= M; i ++) {
        if (is_prime[i]) {
            for (int j = i * 2; j <= M; j += i) {
                is_prime[j] = 0;
            }
        }
    }

    for (int i = 1; i <= M; i ++) {
        is_prime[i] += is_prime[i - 1];
    }

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        if (n <= 3) cout << n - 2 << '\n';
        else cout << is_prime[n] - is_prime[n / 2] << '\n';
    }

    return 0;
}