#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const int M = 1000000;

    vector<int> cost(M + 1);
    for (int i = 0; i <= M; i++) cost[i] = i;

    cost[1] = 0;
    for (int i = 2; i <= M; i++) {
        if ((i & 1) && cost[i] == i) {  
            for (int j = i; j <= M; j += i * 2) {
                cost[j] = i + cost[j / i];
            }
        }
    }

    int t;
    cin >> t;

    while (t--) {
        int n, a, b;
        cin >> n >> a >> b;

        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        vector<long long> adj0, adj1;
        int cnt0 = 0, cnt1 = 0;
        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int x = nums[i];
            long long c1 = 0;

            // 去掉 2 的因子
            while ((x & 1) == 0) {
                x >>= 1;
                c1 += 2;
            }

            long long c0 = cost[x];

            if (c0 < c1) {
                cnt0++;
                ans += c0;
                adj1.push_back(c1 - c0);
            } else {
                cnt1++;
                ans += c1;
                adj0.push_back(c0 - c1);
            }
        }

        sort(adj0.begin(), adj0.end());
        sort(adj1.begin(), adj1.end());

        if (cnt0 < a) {
            for (int i = 0; i < a - cnt0; i++) {
                ans += adj0[i];
            }
        }

        if (cnt1 < b) {
            for (int i = 0; i < b - cnt1; i++) {
                ans += adj1[i];
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
