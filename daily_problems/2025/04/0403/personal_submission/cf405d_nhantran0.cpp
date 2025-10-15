/**
 * https://codeforces.com/problemset/problem/405/D
 * D. Toy Sum
 * Solver: nhant
 * 2025-04-03 21:41:05
 */
#include <bits/stdc++.h>

using namespace std;

void solve() {
    const int S = 1000000;
    vector<bool> has(S + 1);
    int n;
    cin >> n;
    vector<int> x(n);
    for (int& xi : x) {
        cin >> xi;
        has[xi] = true;
    }
    vector<int> res;
    int y = 1;
    for (int xi : x) {
        if (!has[S + 1 - xi]) {
            res.push_back(S + 1 - xi);
        } else if (xi < S + 1 - xi) {
            while (y <= S && (has[y] || has[S + 1 - y])) {
                y++;
            }
            res.push_back(y);
            res.push_back(S + 1 - y);
            y++;
        }
    }
    cout << res.size() << '\n';
    for (int yi : res)
        cout << yi << " ";
    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
}
