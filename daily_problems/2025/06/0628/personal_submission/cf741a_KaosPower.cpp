#include<bits/stdc++.h>

using namespace std;
using i64 = long long;
using u64 = unsigned long long;
using u32 = unsigned;
using u128 = unsigned __int128;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> perm(n);
    for (auto &v: perm)
        cin >> v, v --;

    vector<bool> vis(n, 0);
    int ans = 1;

    for (int i = 0; i < n; i ++) {
        if (!vis[i]) {
            int x = i, c = 0;
            while (!vis[x]) {
                vis[x] = 1;
                x = perm[x];
                c ++;
            }
            if (x != i) return cout << -1, 0;

            if (c % 2 == 0) c /= 2;
            ans = 1ll * ans * c / gcd(ans, c);
        }
    }

    cout << ans;

    return 0;
}
