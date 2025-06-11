#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;
    int l = n, r = 0;
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            l = min(l, i);
            r = max(r, i);
        }
    }
    int ans1 = 1, ans2 = 1;
    for (int i = l + 1; i <= r; i++) {
        if (s1[i - 1] != s2[i])
            ans1 = 0;
        if (s1[i] != s2[i - 1])
            ans2 = 0;
    }
    cout << ans1 + ans2 << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}