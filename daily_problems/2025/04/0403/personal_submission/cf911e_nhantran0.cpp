/**
 * https://codeforces.com/problemset/problem/911/E
 * E. Stack Sorting
 * Solver: nhant
 * 2025-04-03 23:05:40
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<bool> has(n + 1);
    stack<int> st;
    for (int i = 0; i < k; i++) {
        cin >> p[i];
        has[p[i]] = true;
    }
    int bNext = 1;
    int i = 0;
    while (i < k) {
        int opCnt = 0;
        while (st.size() > 0 && st.top() == bNext) {
            st.pop();
            bNext++;
            opCnt++;
        }
        while (st.size() == 0 || (i < k && p[i] < st.top())) {
            st.push(p[i++]);
            opCnt++;
        }
        if (opCnt == 0) break;
    }
    if (i < k) {
        cout << "-1\n";
        return;
    }
    while (st.size() > 0) {
        int x = st.top();
        st.pop();
        while (x > 1 && !has[x - 1]) {
            p[i++] = --x;
        }
    }
    for (int x = n; i < n; i++, x--) {
        p[i] = x;
    }
    for (int x : p)
        cout << x << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
