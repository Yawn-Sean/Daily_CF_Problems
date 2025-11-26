#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int INF = 1e9;

void solve() {
    string s;
    cin >> s;
    int n = s.length();

    vector<vector<int>> nxt(n + 2, vector<int>(10, n));

    vector<int> last_pos(10, n);
    for (int i = n - 1; i >= 0; --i) {
        last_pos[s[i] - '0'] = i;
        for (int d = 0; d < 10; ++d) {
            nxt[i][d] = last_pos[d];
        }
    }

    vector<int> dp(n + 2);
    
    dp[n + 1] = 0;
    dp[n] = 1;

    for (int i = n - 1; i >= 0; --i) {
        int min_len = INF;
        for (int d = 0; d < 10; ++d) {
            int next_index = nxt[i][d];
            int len = 1 + dp[next_index + 1];
            if (len < min_len) {
                min_len = len;
            }
        }
        dp[i] = min_len;
    }


    if (nxt[0][0] == n) {
        cout << "0" << "\n";
        return;
    }
    int best_d = -1;
    int min_len = INF;

    for (int d = 1; d < 10; ++d) {
        int next_index = nxt[0][d];
        int len = 1 + dp[next_index + 1];
        if (len < min_len) {
            min_len = len;
            best_d = d;
        }
    }

    string ans = "";
    ans += to_string(best_d);
    if (nxt[0][best_d] == n) {
        cout << ans << "\n";
        return;
    }
    int curr_idx = nxt[0][best_d] + 1;

    while (true) {
        best_d = -1;
        min_len = INF;

        for (int d = 0; d < 10; ++d) {
            int next_index = nxt[curr_idx][d];
            int len = 1 + dp[next_index + 1];
            if (len < min_len) {
                min_len = len;
                best_d = d;
            }
        }

        ans += to_string(best_d);

        if (nxt[curr_idx][best_d] == n) {
            break;
        }

        // 继续往后跳
        curr_idx = nxt[curr_idx][best_d] + 1;
    }

    cout << ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}
