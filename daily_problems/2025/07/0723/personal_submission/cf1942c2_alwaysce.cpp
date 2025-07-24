#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(x);
        for (int i = 0; i < x; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());

        int ans = x;
        vector<int> intervals;
        for (int i = 1; i < x; i++) {
            int v = a[i] - a[i - 1] - 1;
            if (v % 2) {
                intervals.push_back(v);
            }
        }

        int last_interval = a[0] + n - a[x - 1] - 1;
        if (last_interval % 2) {
            intervals.push_back(last_interval);
        }

        sort(intervals.begin(), intervals.end());

        for (auto& interval: intervals) {
            if (y >= interval / 2) {
                y -= interval / 2;
                ans += interval;
            }
        }

        ans += y * 2;
        cout << min(ans, n) - 2 << "\n";
    }

    return 0;
}
