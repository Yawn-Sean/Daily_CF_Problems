#include <bits/stdc++.h>
using namespace std;

#define ll long long

long double pi = acosl(-1);

void solve(){
    int x1,y1,x2,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    if(x1 == 0 && x2 == 0){
        cout << abs(y1 - y2) << '\n';
    }else if(y1 == 0 && y2 == 0){
        cout << abs(x1 - x2) << '\n';
    }else{
        int mx = abs(x1) + abs(y1);
        int mn = abs(x2) + abs(y2);
        if(mx < mn){
            swap(mx,mn);
        }
        cout << mn * pi / 2 + mx - mn << '\n';
    }
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    cin >> t;

    cout << fixed << setprecision(10);
    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}