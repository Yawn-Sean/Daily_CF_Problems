#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    long long k;
    cin >> n >> k;
    k --;

    vector<int> nums(n);
    for (auto &x: nums) cin >> x;

    sort(nums.begin(), nums.end());

    int i = 0, j;

    while (i < n) {
        j = i;
        while (j < n && nums[i] == nums[j])
            j ++;
        if (k < 1ll * (j - i) * n) break;
        k -= 1ll * (j - i) * n;
        i = j;
    }

    cout << nums[i] << ' ' << nums[k / (j - i)];

    return 0;
}
