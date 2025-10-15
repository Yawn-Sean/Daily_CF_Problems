//  C. Beauty Pageant

#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (auto &v: nums)
        cin >> v;

    sort(nums.rbegin(), nums.rend());

    for (int i = 0; i < n; i ++) {
        for (int j = i; j < n; j ++) {

            cout << i + 1 << ' ';
            for (int k = 0; k < i; k ++) cout << nums[k] << ' ';
            cout << nums[j] << '\n';

            if (--k == 0) return 0;
        }
    }

    return 0;
}
