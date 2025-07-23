#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> nums(n), cnt(m + 1, 0);
    for (auto &v: nums)
        cin >> v, cnt[v] ++;

    int k = *max_element(cnt.begin(), cnt.end());

    sort(nums.begin(), nums.end());

    cout << min(n, 2 * n - 2 * k) << '\n';

    for (int i = 0; i < n; i ++)
        cout << nums[i] << ' ' << nums[(i + k) % n] << '\n';

    return 0;
}
