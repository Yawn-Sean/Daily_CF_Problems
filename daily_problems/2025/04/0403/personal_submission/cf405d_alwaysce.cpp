#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int s = 1e6;
    int n;
    cin >> n;
    vector<int> vis(s + 1);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        vis[x] = 1;
    }

    cout << n << endl;
    for (int i = 1; i <= s; i++) {
        if (!vis[i] && vis[s + 1 - i]) {
            n--;
            vis[i] = 1;
            cout << i << ' ';
        }
    }

    for (int i = 1; i <= s; i++) {
        if (n > 0 && !vis[i] && !vis[s + 1 - i]) {
            n -= 2;
            vis[i] = 1;
            vis[s + 1 - i] = 1;
            cout << i << ' ' << s + 1 - i << ' ';
        }
    }
    return 0;
}
