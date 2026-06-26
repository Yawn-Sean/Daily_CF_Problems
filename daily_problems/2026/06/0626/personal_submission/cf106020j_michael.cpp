#include<bits/stdc++.h>
using namespace std;

#define long long ll

void solve(){
    int n,k;
    cin >> n >> k;
    if(n == 2){
        if((k & -k) == k) cout << 1;
        else cout << 0;
    }else{
        int v = k - n;
        if(n % 2 == 0 && v == n / 2 + 1){
            cout << 1;
        }else{
            cout << max(0,n - 1 - 2 * v);
        }
    }
    cout << '\n';
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