#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;

void solve(){
    int x, y;
    cin >> x >> y;

    int v1 = y, v2 = y, v3 = y;
    int res = 0;
    while (v1!=x || v2!=x || v3!=x){
        vector <int> tmps = {v1, v2, v3};
        sort(tmps.begin(), tmps.end());
        tmps[0] = min(x, tmps[1]+tmps[2]-1);
        res += 1;
        v1 = tmps[0], v2 = tmps[1], v3 = tmps[2];
    }

    cout << res << "\n";
}
