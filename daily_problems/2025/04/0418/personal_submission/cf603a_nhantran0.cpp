/**
 * https://codeforces.com/problemset/problem/603/A
 * A. Alternative Thinking
 * Solver: nhant
 * 2025-04-19 02:49:26
 * https://codeforces.com/problemset/submission/603/316141351
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n;
    string s;
    cin >> n >> s;
    int flipCnt = 0, sameCnt = 0;
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == s[i]) {
            sameCnt++;
        } else {
            flipCnt++;
        }
    }
    cout << (flipCnt + 1 + min(2, sameCnt)) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
