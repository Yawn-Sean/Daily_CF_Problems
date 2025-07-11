#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n, x;
    cin >> n >> x;

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> pre[i];
    }

    vector<int> note(n + 1, 1);
    for (int i = 1; i <= n; i++) {
        note[pre[i]] = 0;
    }

    vector<int> vis(n + 1, 0);
    vector<int> ans;
    int x_offset = 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++) {
        if (note[i] == 0) {
            continue;
        }

        int cur = i;
        int cnt = 0;
        bool flag = false;
        while (cur != 0) {
            ++cnt;
            if (flag || cur == x) {
                flag = true;
                ++x_offset;
            }
            cur = pre[cur];
        }

        if (!flag) {
            for (int j = n; j >= cnt; j--) {
                if (dp[j - cnt]) {
                    dp[j] = 1;
                }
            }
        }
    }

    for (int i = 0; i <= n; i++) {
        if (dp[i]) {
            cout << i + x_offset << endl;
        }
    }
    cout << endl;
    return 0;
}
