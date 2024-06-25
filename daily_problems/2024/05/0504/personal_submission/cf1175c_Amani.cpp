#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<long long> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long sum = INT_MAX, ans;
        for (int i = 0; i + k < n; i++) {
            long long res = arr[i + k] - arr[i];
            if (res < sum) {
                sum = res;
                ans = (arr[i + k] + arr[i]) / 2;
            }
        }
        cout << ans << endl;
    }
}