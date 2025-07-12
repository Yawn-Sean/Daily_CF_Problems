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

    int n;
    cin >> n;

    int cur = 0, cnt = 0, total = 0;
    while (n --) {
        int x;
        cin >> x;

        while (cur < x && cnt) {
            total += cnt & 1;
            cur ++;
            cnt >>= 1;
        }
        cur = x;
        cnt ++;
    }

    while (cnt) {
        total += cnt & 1;
        cur ++;
        cnt >>= 1;
    }

    cout << cur - total;

    return 0;
}