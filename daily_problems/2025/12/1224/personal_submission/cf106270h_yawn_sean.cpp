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

    int M = 1e6;
    vector<int> cost(M + 1);
    iota(cost.begin(), cost.end(), 0);

    cost[1] = 0;
    for (int i = 2; i <= M; i ++) {
        if ((i & 1) && cost[i] == i) {
            for (int j = i; j <= M; j += 2 * i) {
                cost[j] = i + cost[j / i];
            }
        }
    }

    int t;
    cin >> t;

    while (t --) {
        int n, a, b;
        cin >> n >> a >> b;

        long long ans = 0;
        vector<int> adj0, adj1;
        int cnt0 = 0, cnt1 = 0;

        while (n --) {
            int x;
            cin >> x;

            int c0, c1 = 0;

            while (x % 2 == 0) {
                x /= 2;
                c1 += 2;
            }

            c0 = cost[x];

            if (c0 < c1) {
                cnt0 ++;
                ans += c0;
                adj1.emplace_back(c1 - c0);
            }
            else {
                cnt1 ++;
                ans += c1;
                adj0.emplace_back(c0 - c1);
            }
        }

        sort(adj0.begin(), adj0.end());
        sort(adj1.begin(), adj1.end());

        if (cnt0 < a) {
            for (int i = 0; i < a - cnt0; i ++) {
                ans += adj0[i];
            }
        }

        if (cnt1 < b) {
            for (int i = 0; i < b - cnt1; i ++) {
                ans += adj1[i];
            }
        }

        cout << ans << '\n';
    }

	return 0;
}