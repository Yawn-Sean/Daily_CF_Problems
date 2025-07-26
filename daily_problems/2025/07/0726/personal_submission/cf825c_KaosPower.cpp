#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    int ans = 0;

    vector<int> nums(n);
    for (auto &v: nums) cin >> v;

    sort(nums.begin(), nums.end());

    for (auto &v: nums) {
        while (2 * k < v) {
            k <<= 1;
            ans ++;
        }

        k = max(k, v);
    }
    cout << ans;

    return 0;
}
