//  A. Partial Teacher

#include<bits/stdc++.h>

#pragma GCC optimize("O3,Ofast,unroll-loops")

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;
    cin >> n >> s;

    vector<int> ans(n, 1);

    for (int i = 0; i < n - 1; i ++) {
        if (s[i] == 'R') ans[i + 1] = ans[i] + 1;
        else if (s[i] == '=') ans[i + 1] = ans[i];
    }

    for (int i = n - 2; i >= 0; i --) {
        if (s[i] == 'L') ans[i] = max(ans[i], ans[i + 1] + 1);
        else if (s[i] == '=') ans[i] = ans[i + 1];
    }

    for (auto &x: ans) cout << x << ' ';

    return 0;
}
