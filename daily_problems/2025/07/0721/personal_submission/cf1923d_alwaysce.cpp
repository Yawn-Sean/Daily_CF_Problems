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
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }

        vector<int> left(n, -1), right(n, n);
        iota(left.begin(), left.end(), 0);
        iota(right.begin(), right.end(), 0);

        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (a[i] == a[i - 1]) {
                    left[i] = left[i - 1];
                }
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            if (i < n - 1) {
                if (a[i] == a[i + 1]) {
                    right[i] = right[i + 1];
                }
            }
        }

        vector<i64> preS(n + 1);
        for (int i = 1; i <= n; i++) {
            preS[i] = preS[i - 1] + a[i - 1];
        }

        vector<int> ans(n, 1e9);
        for (int i = 0; i < n; i++) {
            // check left
            int i1 = i - 1;
            if (i1 >= 0) {
                int l = 0, r = i1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (preS[i] - preS[mid] > a[i]) l = mid + 1;
                    else r = mid - 1;
                }
                r = min(r, left[i1] - 1);
                if (r >= 0) ans[i] = min(ans[i], i - r);
                if (a[i - 1] > a[i]) ans[i] = 1;
            }

            // check right
            int i2 = i + 1;
            if (i2 < n) {
                int l = i2, r = n - 1;
                while (l <= r) {
                    int mid = (l + r) / 2;
                    if (preS[mid + 1] - preS[i + 1] > a[i]) r = mid - 1;
                    else l = mid + 1;
                }
                l = max(l, right[i + 1] + 1);
                if (l < n) ans[i] = min(ans[i], l - i);
                if (a[i + 1] > a[i]) ans[i] = 1;
            }
        }
        
        for (int i = 0; i < n; i++) {
            if (ans[i] == 1e9) {
                ans[i] = -1;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}
