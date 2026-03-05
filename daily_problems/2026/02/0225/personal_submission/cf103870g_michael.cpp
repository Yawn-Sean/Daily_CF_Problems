#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int l,r,m;
    cin >> l >> r >> m;
    int k = 31 - __builtin_clz(m);
    cout << ((r + 1) >> k) - (l >> k) << '\n';
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