#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <cmath>

using namespace std;
using ll = long long;

const int MAX_M = 1e6 + 5;

ll qpow(ll a, ll b, ll mod) {
    ll res = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int min_prime[MAX_M];
bool has_div[MAX_M];

void precompute_sieve() {
    vector<int> primes;
    iota(min_prime, min_prime + MAX_M, 0);
    
    for (int i = 2; i < MAX_M; ++i) {
        if (min_prime[i] == i) {
            primes.push_back(i);
        }
        for (int p : primes) {
            if (p > min_prime[i] || (ll)i * p >= MAX_M) break;
            min_prime[i * p] = p;
        }
    }
}

void solve() {
    int n, q;
    if (!(cin >> n >> q)) return;

    vector<int> nums(n);
    for (int &x : nums) cin >> x;

    if (n == 2) {
        while (q--) {
            int x; 
            cin >> x;
            bool ok = (qpow(nums[0], nums[1], x) == 0) || 
                      (qpow(nums[1], nums[0], x) == 0);
            cout << (ok ? "Yes" : "No") << '\n';
        }
        return;
    }

    if (n == 3) {
        sort(nums.begin(), nums.end());
        while (q--) {
            int x;
            cin >> x;
            bool found = false;
            
            vector<int> p = nums; 
            sort(p.begin(), p.end());

            do {
                int a = p[0], b = p[1], c = p[2];

                int va = qpow(a, min(20, b), x);
                
                ll pb = 1; 
                for(int k = 0; k < min(c, 5); ++k) pb = min((ll)20, pb * b);

                int vb = qpow(b, min(20, c), x);
                ll pa = 1;
                for(int k = 0; k < min(b, 5); ++k) pa = min((ll)20, pa * a);

                if (qpow(va, pb, x) == 0 || qpow(vb, pa, x) == 0) {
                    found = true;
                    break;
                }

            } while (next_permutation(p.begin(), p.end()));

            cout << (found ? "Yes" : "No") << '\n';
        }
        return;
    }

    int cnt1 = 0;
    for (int v : nums) if (v == 1) cnt1++;

    if (cnt1 >= n - 1) {
        int max_val = *max_element(nums.begin(), nums.end());
        while (q--) {
            int x;
            cin >> x;
            cout << (max_val % x == 0 ? "Yes" : "No") << '\n';
        }
        return;
    }

    fill(has_div, has_div + MAX_M, false);
    for (int x : nums) has_div[x] = true;

    for (int i = 1; i < MAX_M; ++i) {
        for (int j = i; j < MAX_M; j += i) {
            has_div[i] |= has_div[j];
        }
    }

    vector<bool> final_check(MAX_M, false);
    
    for (int i = 1; i < MAX_M; ++i) {
        int cur = i;
        int rad = 1;
        while (cur > 1) {
            int p = min_prime[cur];
            rad *= p;
            while (cur % p == 0) cur /= p;
        }
        if (has_div[rad]) {
            final_check[i] = true;
        }
    }

    while (q--) {
        int x;
        cin >> x;
        cout << (final_check[x] ? "Yes" : "No") << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    precompute_sieve();
    solve();

    return 0;
}
