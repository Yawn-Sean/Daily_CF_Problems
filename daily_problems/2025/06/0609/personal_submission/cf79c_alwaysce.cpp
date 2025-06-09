#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;
i64 inf = 1e18;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n;
    cin >> n;

    vector<string> forbid(n);
    for (int i = 0; i < n; ++i) {
        cin >> forbid[i];
    }


    int m = s.size();
    vector<vector<int>> pos(n);

    for (int j = 0; j < n; ++j) {
        string& f = forbid[j];
        int len = f.size();
        for (int i = 0; i <= m - len; ++i) {
            if (s.substr(i, len) == f) {
                pos[j].push_back(i);
            }
        }
    }
    

    int left = 0, ans = 0, ans_l = 0;
    vector<int> pts(n, 0);
    while (left < m) {
        int nxt_left = left + 1;
        int right = m - 1;

        for (int j = 0; j < n; j++) {
            while (pts[j] < pos[j].size() && pos[j][pts[j]] < left) {
                pts[j]++;
            }
            if (pts[j] < pos[j].size()) {
                int nxt_right = pos[j][pts[j]] + (int)forbid[j].size() - 2;
                if (nxt_right < right) {
                    right = nxt_right;
                    nxt_left = pos[j][pts[j]] + 1;
                } else if (nxt_right == right) {
                    nxt_left = max(nxt_left, pos[j][pts[j]] + 1);
                }
            }
        }

        if (right - left + 1 > ans) {
            ans = right - left + 1;
            ans_l = left;
        }
        left = nxt_left;
    }
    cout << ans << ' ' << ans_l << endl;
    return 0;
}
