#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    auto query = [&](string s)->int{
        cout << "? " << s << "\n" << flush;
        int res;
        cin >> res;
        return res;
    };
    auto make = [&](int len)->string {
        string res;
        for (int i = 1; i <= len; ++ i) res += '0';
        for (int i = 1; i <= n-len; ++ i) res += '1';
        return res;
    };

    int l = 1, r = n;
    int c1 = query(make(n));
    int pos0 = -1, pos1 = -1;
    int sumL = 0, sumR = 0;
    while (l < r){
        int mid = l+r >> 1;
        int c2 = query(make(mid));
        int len = n - mid;
        int x = (c1+c2-len)/2-sumL;
        int y = c1-(x+sumL)-sumR;
        int L1 = mid-l+1, L2 = r-mid;
        assert(x >= 0);
        assert(y >= 0);
        assert((c1+c2-len)%2==0);
        if (y == 0) pos0 = mid+1;
        if (y == L2) pos1 = mid+1;
        if (x == 0) pos0 = mid;
        if (x == L1) pos1 = mid;

        if (x > 0 && L1 != x){
            sumR += y;
            r = mid;
        } else if (y > 0 && L2 != y){
            sumL += x;
            l = mid+1;
        } else if (x == 0){
            l = mid+1;
        } else if (x == L1){
            sumL += x;
            l = mid+1;
        } else if (y == 0){
            r = mid;
        } else {
            sumR += y;
            r = mid;
        }
    }

    cout << "! " << pos0 << " " << pos1 << "\n" << flush;
}
