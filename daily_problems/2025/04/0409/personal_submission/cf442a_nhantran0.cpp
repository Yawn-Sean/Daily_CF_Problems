/**
 * https://codeforces.com/problemset/problem/442/A
 * A. Borya and Hanabi
 * Solver: nhant
 * 2025-04-10 04:10:22
 * Submission: https://codeforces.com/problemset/submission/442/314808659
 */
#include <bits/stdc++.h>

using namespace std;

int colorToIdx(char c) {
    switch (c) {
        case 'R':
            return 0;
        case 'G':
            return 1;
        case 'B':
            return 2;
        case 'Y':
            return 3;
        case 'W':
            return 4;
    };
    return -1;
}

void solve() {
    int n;
    cin >> n;
    string s;
    vector<vector<bool>> has(5, vector<bool>(5));
    while (n--) {
        cin >> s;
        int colorI = colorToIdx(s[0]);
        int valI = s[1] - '1';
        has[colorI][valI] = true;
    }
    int res = 25;
    bitset<1024> b;
    for (int rowMask = 0, rowMaskEnd = (1 << 5); rowMask < rowMaskEnd; rowMask++) {
        for (int colMask = 0, colMaskEnd = (1 << 5); colMask < colMaskEnd; colMask++) {
            b.reset();
            bool dup = false;
            for (int r = 0; r < 5; r++) {
                for (int c = 0; c < 5; c++) {
                    if (has[r][c]) {
                        int x = (rowMask & (1 << r)) + ((colMask & (1 << c)) << 5);
                        if (b[x]) {
                            dup = true;
                        }
                        b[x] = true;
                    }
                }
            }
            if (!dup) res = min(res, __builtin_popcount(rowMask) + __builtin_popcount(colMask));
        }
    }
    cout << res << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
