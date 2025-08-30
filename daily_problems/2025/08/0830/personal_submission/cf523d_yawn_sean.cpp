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

    int n, k;
    cin >> n >> k;

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < k; i ++) pq.push(0);

    while (n --) {
        long long s, m;
        cin >> s >> m;

        long long t = pq.top(); pq.pop();
        t = max(t, s) + m;

        cout << t << '\n';
        pq.push(t);
    }

    return 0;
}