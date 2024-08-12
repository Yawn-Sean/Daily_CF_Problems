#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    ranges::sort(arr);
    int len = 0, s = 0, l = 0, ans;
    for (int i = 0; i < n; ++i) {
        s += arr[i];
        while (arr[i] * (i-l+1) - s > k) {
            s -= arr[l];
            l++;
        }
        if (i - l + 1 > len) {
            len = i - l + 1;
            ans = arr[i];
        }
    }
    cout << len << " " << ans;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    solve();
    return 0;
}