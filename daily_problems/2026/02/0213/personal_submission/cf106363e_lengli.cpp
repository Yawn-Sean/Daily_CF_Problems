#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[nums[i]] = i;
    }

    int l = pos[0], r = pos[0];

    vector<long long> diff_0(n + 1, 0);
    vector<long long> diff_1(n + 1, 0);

    for (int i = 0; i < n; i++) {
        l = min(l, pos[i]);
        r = max(r, pos[i]);

        diff_0[l] += 1LL * (n - r) * (l + 1);
        diff_0[r + 1] -= 1LL * (n - r) * (l + 1);

        diff_1[0] += (n - r);
        diff_1[l] -= (n - r);
        diff_0[0] += (n - r);
        diff_0[l] -= (n - r);

        diff_1[r + 1] -= (l + 1);
        diff_1[n] += (l + 1);
        diff_0[r + 1] += 1LL * (l + 1) * n;
        diff_0[n] -= 1LL * (l + 1) * n;
    }
    for (int i = 0; i < n; i++) {
        diff_0[i + 1] += diff_0[i];
        diff_1[i + 1] += diff_1[i];
    }

    for (int i = 0; i < n; i++) {
        cout << diff_1[i] * i + diff_0[i] << '\n';
    }

    return 0;
}
