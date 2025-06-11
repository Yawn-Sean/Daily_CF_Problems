#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> ans(n * 2);
    for (int i = 0; i < n / 2; i++) {
        ans[i] = ans[n - 1 - i] = i * 2 + 1;
        ans[n + i] = ans[2 * n - 2 - i] = i * 2 + 2;
    }
    for (auto &x: ans)
        cout << (x ? x : n) << ' ';

    return 0;
}