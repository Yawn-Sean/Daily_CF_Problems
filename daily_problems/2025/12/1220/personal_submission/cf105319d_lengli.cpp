#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> nums(n);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int l = 0, r = 0;
    long long ans = 0;

    vector<int> c0(30, 0), c1(30, 0);

    while (l < n) {
        while (r + 1 < n) {
            int x = nums[r] ^ nums[r + 1];
            int v = (x == 0 ? -1 : 31 - __builtin_clz(x)); 

            if (v >= 0) {
                if ((nums[r] >> v) & 1) {
                    if (c0[v]) break;
                    c1[v]++;
                } else {
                    if (c1[v]) break;
                    c0[v]++;
                }
            }
            r++;
        }

        ans += (r - l + 1);

        if (l + 1 < n) {
            int x = nums[l] ^ nums[l + 1];
            int v = (x == 0 ? -1 : 31 - __builtin_clz(x));
            if (v >= 0) {
                if ((nums[l] >> v) & 1) c1[v]--;
                else c0[v]--;
            }
        }
        l++;
    }

    cout << ans << '\n';
    return 0;
}
