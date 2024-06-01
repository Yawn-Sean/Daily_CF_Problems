#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        vector<int> a(n);
        long long total = 0LL;
        cin >> a[0];
        int b = a[0];
        for (int i = 1; i < n; i++) {
            cin >> a[i];
            total += abs(a[i] - b);
            b = a[i];
        }
        // insert 1 and x into different position
        int cost_mn1 = INT_MAX;
        vector<int> cost_x(n);
        vector<int> cost_1(n);
        cost_x[0] = abs(a[0] - x);
        cost_1[0] = abs(a[0] - 1);
        for (int i = 1; i < n; i++) {
            cost_x[i] = min(cost_x[i - 1], abs(a[i - 1] - x) + abs(a[i] - x) - abs(a[i] - a[i - 1]));
            cost_1[i] = min(cost_1[i - 1], abs(a[i - 1] - 1) + abs(a[i] - 1) - abs(a[i] - a[i - 1]));
        }
        for (int i = 1; i < n; i++) {
            cost_mn1 = min(cost_mn1, cost_x[i - 1] + abs(a[i - 1] - 1) + abs(a[i] - 1) - abs(a[i] - a[i - 1]));
            cost_mn1 = min(cost_mn1, cost_1[i - 1] + abs(a[i - 1] - x) + abs(a[i] - x) - abs(a[i] - a[i - 1]));
        }
        cost_mn1 = min(cost_mn1, cost_x[n - 1] + abs(a[n - 1] - 1));
        cost_mn1 = min(cost_mn1, cost_1[n - 1] + abs(a[n - 1] - x));
        // insert 1 and x into same position
        int cost_mn2 = min(abs(a[0] - x), abs(a[0] - 1));
        for (int i = 1; i < n; i++) {
            int t = min(abs(a[i] - x) + abs(a[i - 1] - 1), abs(a[i] - 1) + abs(a[i - 1] - x));
            cost_mn2 = min(cost_mn2, t - abs(a[i] - a[i - 1]));
        }
        cost_mn2 = min(cost_mn2, min(abs(a[n - 1] - x), abs(a[n - 1] - 1)));
        total += min(cost_mn1, cost_mn2 + x - 1);
        cout << total << "\n";
    }
    return 0;
}

