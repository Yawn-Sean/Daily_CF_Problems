#include <bits/stdc++.h>
using namespace std;
#define int long long

int solve() {
    int x, y;
    cin >> x >> y;
    int ans = 2;
    vector<int> arr(3);
    arr[0] = arr[1] = arr[2] = y;
    while (arr[0] < x) {
        ranges::sort(arr);
        arr[0] = arr[1] + arr[2] - 1;
        ans++;
    }
    return ans;
}

signed main() {
    cout << solve();
    return 0;
}