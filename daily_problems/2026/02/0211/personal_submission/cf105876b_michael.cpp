#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    int n;
    cin >> n;
    
    if(n % 4 == 3){
        cout << "-1\n";
    }else{
        for(int i = 1; i <= n; ++i){
            if(i + 1 <= n && i % 4 == 3){
                cout << i + 1 << ' ' << i << ' ';
                i++;
            }else{
                cout << i << ' ';
            }
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;

    while(t--){
        solve();
    }
    cout << flush;
    return 0;
}
