#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

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