/*
L: del_l[i] = min(del_l[i-1]+1, h[i])
R: del_r[i] = min(del_r[i+1]+1, h[i])
i: del[i] = min(del_l[i], del_r[i])
 */
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXLEN = 1e5+2;

int main() {
    int i, n, ans = 0;
    cin >> n;
    int h[MAXLEN], del_l[MAXLEN], del_r[MAXLEN];
    for (i = 1; i <= n; i++) {
        cin >> h[i];
    }
    del_l[0] = del_l[n+1] = del_r[0] = del_r[n+1] = 0;
    for (i = 1; i <= n; i++) {
        del_l[i] = min(del_l[i-1]+1, h[i]);
        del_r[n-i+1] = min(del_r[n-i+2]+1, h[n-i+1]);
    }
    for (i = 1; i <= n; i++) {
        ans = max(ans, min(del_l[i], del_r[i]));
    }
    cout << ans << endl;
    return 0;
}