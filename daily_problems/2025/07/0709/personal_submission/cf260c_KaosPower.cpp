#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, x;
    cin >> n >> x;

    vector<long long> nums(n);
    for (auto &v: nums) cin >> v;

    x --;
    long long mn = *min_element(nums.begin(), nums.end());

    for (auto &v: nums) v -= mn;
    mn *= n;

    while (nums[x]) {
        nums[x] --, mn ++;
        x = (x + n - 1) % n;
    }

    nums[x] = mn;
    for (auto &v: nums) cout << v << ' ';

    return 0;
}
