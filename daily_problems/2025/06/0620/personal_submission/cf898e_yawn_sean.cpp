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

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    vector<int> v1, v0;

    for (auto &v: nums) {
        int x = sqrt(v);
        if (x * x == v) v0.emplace_back(v ? 1 : 2);
        else v1.emplace_back(min(v - x * x, (x + 1) * (x + 1) - v));
    }

    sort(v0.rbegin(), v0.rend());
    sort(v1.rbegin(), v1.rend());

    long long ans = 0;
    for (int i = n / 2; i < v0.size(); i ++) ans += v0[i];
    for (int i = n / 2; i < v1.size(); i ++) ans += v1[i];

    cout << ans;

    return 0;
}