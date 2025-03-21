#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    int n;
    cin >> n;
    i64 tot = 0, mx = 0;
    while (n--) {
        i64 x;
        cin >> x;
        tot += x;
        mx = max(mx, x);
    }
    /*任意一个三角形中至少有 1 个点不在这条边上 */
    cout << min(tot / 3, tot - mx) << endl;
    return 0;
}
