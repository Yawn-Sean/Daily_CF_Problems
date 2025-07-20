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

    long long n, k;
    cin >> n >> k;

    int p;
    cin >> p;

    while (p --) {
        long long x;
        cin >> x;

        if (k == 0) cout << '.';
        else {
            long long vn = n, vk = k;
            if (n & 1) {
                if (x == n) {
                    cout << 'X';
                    continue;
                }
                vn --, vk --;
            }
            
            if (vk * 2 <= vn)
                if (x % 2 == 0 && x / 2 + vk > vn / 2) cout << 'X';
                else cout << '.';
            else
                if (x % 2 == 0) cout << 'X';
                else if ((x + 1) / 2 + (vk - vn / 2) > vn / 2) cout << 'X';
                else cout << '.';
        }
    }

    return 0;
}