#include <bits/stdc++.h>  
typedef long long ll;  
using namespace std;  
void solve(){
    string s1;
    string s2;
    int cnt1 = 0;
    int cnt2 = 0;
    cin >> s1 >> s2;
    for(auto i : s1){
        if(i == '1'){
            cnt1++;
        }
    }
    for(auto i : s2){
        if(i == '1'){
            cnt2++;
        }
    }
    if(cnt1 % 2){
        cnt1++;
    }
    if(cnt1 >= cnt2){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
    return;
}  
int main() {  
    ios_base::sync_with_stdio(false);  
    cin.tie(0);  
    cout.tie(0);  
    ll t = 1;  
    while (t--) {  
        solve();  
    }  
    return 0;  
}
