#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, m;
    cin >> n >> m;
    /*

    */
    vector<int> nums(n), pos(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    vector<int> forbid(n + 1, -1);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        // u作为右侧 左边最后一个不能一起共存的位置
        if (pos[u] < pos[v]) {
            forbid[v] = max(forbid[v], pos[u]);
        } 
        if (pos[v] < pos[u]) {
            forbid[u] = max(forbid[u], pos[v]);
        }
    }

    int left = 0;
    i64 ans = 0;

    for (int right = 0; right < n; right++) {
        int to_add = nums[right];
        int forbid_pos = forbid[to_add];
        while (left < right && left <= forbid_pos) {
            left++;
        }
        ans += 1ll * (right - left + 1);
    }
    cout << ans << endl;
    return 0;
}
