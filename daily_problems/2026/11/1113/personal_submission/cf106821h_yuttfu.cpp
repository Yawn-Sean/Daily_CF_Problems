#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    cin >> n;
    map<int,int> cnt;
    int x;
    for(int i = 1;i <= n;i++){
        cin >> x;
        if(x < n) cnt[x] ++;
    }
    if(cnt.find(0) == cnt.end()){
        cout << "Tie\n";
        return;
    }
    int mex = 0;
    while(cnt.find(mex) != cnt.end()) mex ++;
    if(n % 2){
        cout << "Dinny\n";
    }else{
        for(const auto &[u,v] : cnt){
            if(u > mex) break;
            if(v == 1){
                cout << "Dinny\n";
                return;
            }
        }
        cout << "Tie\n";
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T = 1;
    // cin >> T;
    while(T --){
        solve();
    }
    return 0;
}
