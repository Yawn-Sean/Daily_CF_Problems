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

    int t;
    cin >> t;

    while (t --) {
        int n;
        cin >> n;

        vector<int> nums(n), perm(n);
        for (auto &v: nums) cin >> v;
        for (auto &v: perm) cin >> v, v --;

        priority_queue<int, vector<int>, greater<int>> pq;
        long long ans = 0;
        int chosen = 0;

        for (int i = n - 1; i >= 0; i --) {
            pq.push(nums[perm[i]]);
            while (pq.size() > i + 1) pq.pop();
            if (pq.size() == i + 1 && 1ll * pq.top() * pq.size() >= ans) {
                ans = 1ll * pq.top() * pq.size();
                chosen = pq.size();
            }
        }

        cout << ans << ' ' << chosen << '\n';
    }

    return 0;
}