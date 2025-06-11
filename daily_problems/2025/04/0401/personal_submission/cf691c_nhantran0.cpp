/**
 * https://codeforces.com/problemset/problem/691/C
 * C. Exponential notation
 * Solver: nhant
 * 2025-04-01 19:05:12
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    string s;
    cin >> s;
    int n = int(s.size()), firstNumI = -1, lastNumI = n, dotI = n;
    for (int i = 0; i < n; i++) {
        if (s[i] == '.') {
            dotI = i;
        } else if (s[i] != '0') {
            if (firstNumI == -1) firstNumI = i;
            lastNumI = i;
        }
    }
    stringstream t;
    t << s[firstNumI];
    // decimal
    if (firstNumI < lastNumI) {
        t << '.';
        for (int i = firstNumI + 1; i <= lastNumI; i++) {
            if (s[i] != '.') t << s[i];
        }
    }
    // exponential
    if (firstNumI + 1 != dotI) {
        int p;
        if (dotI < firstNumI) {
            t << "E-";
            p = firstNumI - dotI;
        } else {
            t << "E";
            p = dotI - firstNumI - 1;
        }
        stack<char> st;
        while (p) {
            st.push((char)('0' + (p % 10)));
            p /= 10;
        }
        while (st.size() > 0) {
            t << st.top();
            st.pop();
        }
    }
    cout << t.str() << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
