#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    string s;
    cin >> n >> s;
    int ans = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            ans++;
        }
    }

    ans = min(ans + 3, n);
    cout << ans << endl;
    return 0;
}
