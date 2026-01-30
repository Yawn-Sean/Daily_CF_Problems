#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    ll sx,sy,tx,ty,k;
    cin >> sx >> sy >> tx >> ty >> k;
    ll dx = abs(tx - sx);
    ll dy = abs(ty - sy);
    
    if(dx < dy){
        ll tmp = dx;
        dx = dy;
        dy = tmp;
    }

    if(dx <= (dy + 1) * k){
        cout << dx + dy << '\n';
    }else{
        cout << dx + dy + (dx - (dy + 1) * k + 2 * k - 1) / (2 * k) * 2 << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}