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

    vector<int> vals = {0}, adds = {0};
    long long total = 0;

    cout << fixed << setprecision(9);

    while (n --) {
        int t;
        cin >> t;

        if (t == 1) {
            int cnt, val;
            cin >> cnt >> val;

            total += cnt * val;
            adds[cnt - 1] += val;
        }
        else if (t == 2) {
            int val;
            cin >> val;

            total += val;

            vals.emplace_back(val);
            adds.emplace_back(0);
        }
        else {
            adds[adds.size() - 2] += adds.back();
            total -= adds.back() + vals.back();

            vals.pop_back();
            adds.pop_back();
        }

        cout << (long double)1 * total / vals.size() << '\n';
    }

    return 0;
}