/*
 https://codeforces.com/problemset/problem/877/C
 C. Slava and tanks
 Solver: nhant
 2025-05-10 04:25:59
 https://codeforces.com/problemset/submission/877/318987489
*/
#include <bits/stdc++.h>

using namespace std;

void solve() {
    int m;
    cin >> m;
    cout << ((m / 2) * 2 + (m + 1) / 2) << '\n';
    auto pr_alter = [&](int start) {
        for (int i = start; i <= m; i += 2) {
            cout << i << " ";
        }
    };
    pr_alter(2);
    pr_alter(1);
    pr_alter(2);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
