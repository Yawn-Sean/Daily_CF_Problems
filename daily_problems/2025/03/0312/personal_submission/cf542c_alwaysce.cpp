#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto&x : nums) {
        cin >> x;
        --x;
    }

    i64 ans = 1;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        vector<int> vis(n, -1);
        vis[i] = 0;
        int cur = i;
        while (1) {
            int nxt = nums[cur];
            if (vis[nxt] != -1) {
                int L = vis[cur] + 1 - vis[nxt]; // 环的长度
                ans = ans / gcd(ans, L) * L; // lcm
                mx = max(mx, vis[nxt]); // 进入环的最后一个位置
                break;
            }

            vis[nxt] = vis[cur] + 1;
            cur = nxt;
        }
    }

    i64 res = ans;
    while (res < mx) {
        res += ans;
    }
    cout << res << endl;
    return 0;
}
