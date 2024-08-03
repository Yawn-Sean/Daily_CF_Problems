#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#define int long long

#ifdef LOCAL
#include "C:\Program Files\DEBUG\debug.h"
#else
#define debug(...) 114514
#define ps 114514
#endif

signed main() {
    IOS int n, k;
    cin >> n >> k;
    cout <<  (6 * n - 1) * k << endl;
 
    for (int i = 1; i <= n; i++) {
    
        cout << k * (6  * (i - 1) + 2 ) << ' ' <<   k * (6  * (i - 1) + 1 )<< ' ' << k * (6 * (i - 1) + 3 )<< ' ' << k * (6 * (i - 1) + 5)<< endl;
    }
    return 0;
}
