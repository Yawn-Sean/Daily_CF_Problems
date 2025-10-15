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

    priority_queue<int, vector<int>, greater<int>> pq;
    long long chosen = 0, total = 0;

    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;

        int cur = i / 2 + 1;
        if (cur > pq.size()) {
            chosen += x;
            pq.push(x);
        }
        else if (pq.top() < x) {
            chosen -= pq.top();
            pq.pop();
            chosen += x;
            pq.push(x);
        }
        total += x;
    }

    cout << chosen << ' ' << total - chosen;

    return 0;
}