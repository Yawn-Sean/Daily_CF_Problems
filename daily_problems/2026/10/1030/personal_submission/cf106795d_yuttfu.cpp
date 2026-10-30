#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    int l = 0,r = 0;
    vector<int> res;
    int ans = 0;
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(i > 0 && s[i] == s[i-1]){flag = false;}
        if(s[i] == 'G') ans += 1;
        else ans += 2;
        ans %= 3;
    }
    if(flag){
        cout << n << '\n';
        return;
    }
    cout << (ans % 3 ? 1 : 2) << '\n'; 
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
