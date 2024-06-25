#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, a;
    cin >> n;
    vector<int> cnt(n + 1, 0), nums;
    for (int i = 0; i < n; i++) {
        cin >> a;
        cnt[a]++;
    }
    int mn = n;
    for (int i = 1; i <= n; i++) {
        if (cnt[i] > 0) {
            nums.push_back(cnt[i]);
            if (cnt[i] < mn) mn = cnt[i];
        }
    }
    for (int i = mn + 1; i >= 2; i--) {
        int sum = 0;
        bool ok = true;
        for (int x : nums) {
            int a = (x + i - 1) / i;
            int b = a * i - x;
            if (a < b) {
                ok = false;
                break;
            }
            sum += a;
        }
        if (ok) {
            cout << sum << "\n";
            return;
        }
    }
}

int main() {
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
