#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;

    auto query = [&](int x, int y)->string{
        cout << x << " " << y << "\n" << flush;
        string ans;
        cin >> ans;
        return ans;
    };

    string bg = query(0, 0);
    int l = 1, r = 1e9-1, mid = l+r>>1, cur = 1;
    -- n;
    while (n > 1){
        -- n;
        mid = l+r+1 >> 1;
        cur = query(mid, 0)==bg ? 1 : -1;
        if (cur==1) l = mid+1;
        else r = mid-1;
    }
    int res = cur==1 ? l : r;
    if (n) cur = query(res, 1e8)==bg ? 1 : -1;
    cout << res << " " << 0 << " " << res+cur << " " << 100000000 << "\n" << flush;
}
