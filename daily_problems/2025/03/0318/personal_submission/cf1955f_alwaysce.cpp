#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int t;
    cin >> t;
    while (t--) {
        vector<int> p(4);
        for (int i = 0; i < 4; i++) {
            cin >> p[i];
        }

        int ans = p[0] / 2 + p[1] / 2 + p[2]/2 + p[3]/2;
        ans += (p[0]%2)&(p[1]%2)&(p[2]%2);
        cout << ans << endl;
    }
    return 0;
}
