/**
 * https://codeforces.com/problemset/problem/845/D
 * D. Driving Test
 * Solver: nhant
 * 2025-04-28 21:08:06
 * https://codeforces.com/problemset/submission/845/317574969, 93 ms, 100 KB
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    cin >> n;
    stack<int> spdLim;
    int res = 0, spd = 0, noOverTakeCnt = 0;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            cin >> spd;
            while (spdLim.size() > 0 && spdLim.top() < spd) {
                spdLim.pop();
                res++;
            }
        } else if (t == 2) {
            if (noOverTakeCnt > 0) {
                res += noOverTakeCnt;
                noOverTakeCnt = 0;
            }
        } else if (t == 3) {
            int sl;
            cin >> sl;
            if (sl < spd) {
                res++;
            } else {
                spdLim.push(sl);
            }
        } else if (t == 4) {
            noOverTakeCnt = 0;
        } else if (t == 5) {
            while (spdLim.size() > 0) {
                spdLim.pop();
            }
        } else if (t == 6) {
            noOverTakeCnt++;
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
