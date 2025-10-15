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

    int n, pos;
    cin >> n >> pos;

    vector<int> prev(n + 1);
    for (int i = 1; i <= n; i ++)
        cin >> prev[i];

    vector<bool> note(n + 1, 1);
    for (int i = 1; i <= n; i ++)
        note[prev[i]] = 0;

    vector<bool> dp(n + 1, 0);
    int relative_pos;

    dp[0] = 1;

    for (int i = 1; i <= n; i ++) {
        if (note[i]) {
            int cur = i, cnt = 0;
            bool flg = false;

            while (cur) {
                cnt ++;
                if (cur == pos) {
                    flg = true;
                    relative_pos = cnt;
                }
                cur = prev[cur];
            }

            if (flg) relative_pos = cnt + 1 - relative_pos;
            else {
                for (int j = n; j >= cnt; j --) {
                    if (dp[j - cnt]) {
                        dp[j] = 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i <= n; i ++)
        if (dp[i]) cout << i + relative_pos << '\n';

    return 0;
}
