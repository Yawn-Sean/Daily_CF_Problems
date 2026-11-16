#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    cout << "? " << 2 << endl;
    int tr;
    cin >> tr;
    tr = (tr == 1 ? 1 : 2);
    int l = 1,r = 1000000001;
    while(l + 2 < r){
        int m = l + r >> 1;
        if(!(m&1)) m ++;
        cout << "? " << m << endl;
        int res;
        cin >> res;
        if(res == (tr&1)) r = m;
        else l = m;
    }
    cout << "! " << (tr & 1 ? l : l+1) << endl;
}

int main(){
    // ios::sync_with_stdio(0);
    // cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
