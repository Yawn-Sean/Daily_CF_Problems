#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int n;
    cin >> n;
    string s;
    cin >> s;

    int v = 0;
    for (int i = 0; i < n; i++) {
        v += (((s[i] - '1') & 1) == (i & 1));
    }
    cout << min(v, n - v) << '\n';
    return 0;
}
