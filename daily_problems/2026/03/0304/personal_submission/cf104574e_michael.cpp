#include <bits/stdc++.h>
using namespace std;

#define ll long long

void solve(){
    vector<int> num(52);
    for(int i = 0; i < 52; ++i){
        cin >> num[i];
    }
    for(int i = 0; i < 8; ++i){
        vector<int> nnum;
        for(int j = 0; j < 26; ++j){
            nnum.emplace_back(num[j]);
            nnum.emplace_back(num[j + 26]);
        }
        swap(num,nnum);
        bool flag = true;
        for(int i = 26; i < 52; ++i){
            if(num[i] == 1){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
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