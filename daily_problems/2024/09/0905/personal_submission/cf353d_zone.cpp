#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

void solve() {
    string str;
    cin >> str;

    int n = str.size();
    int l = 0, r = n - 1;
    while (l <= r && str[l] == 'F') l ++;
    while (l <= r && str[r] == 'M') r --;

    int ans = 0, cnt = 0;
    for (int i = l; i <= r; i ++ ) {
        if (str[i] == 'F') ans = max(ans + 1, cnt);
        else cnt ++;
    }

    cout << ans << endl;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
