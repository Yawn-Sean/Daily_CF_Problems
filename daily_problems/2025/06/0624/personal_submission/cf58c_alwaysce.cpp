#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    map<int, int> cnt;    
    for (int i = 0; i < n / 2; i++) {
        cnt[(a[i] - i - 1)]++;
    }

    for (int i = n / 2 + (n % 2); i < n; i++) {
        cnt[(a[i] - (n - i))]++;
    }

    
    int ans = n;
    if (n % 2 == 1) {
        for (auto& [k, v]: cnt) {
            if (k < 0) {
                continue;
            }
            int add = 0;
            if (a[n / 2] - (n / 2) - 1 == k) {
                add = 1;
            }
            ans = min(ans, n - v - add);
        }
    } else {
        for (auto& [k, v] : cnt) {
            if (k < 0) {
                continue;
            }
            ans = min(ans, n - v);
        }
    }
    cout << ans << endl;

    return 0;
}
