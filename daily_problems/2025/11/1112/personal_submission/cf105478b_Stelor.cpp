#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;


void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = "#" + s;
    int lst = 0;
    int ans = 0;
    for (int i = 1;i <= n; ++i){
        if (s[i] != '?'){
            lst = 0;
            ans++;
        }else{
            if (lst == 0){
                if (i != n && s[i + 1] == '?'){
                    lst = i;
                }else if (i != 1 && i != n && s[i + 1] != '?' && s[i + 1] != s[i - 1]){
                    ans++;
                }
                
            }else{
                if (i != n){
                    if (s[i + 1] == '?'){
                    }else{
                        if (lst != 1){
                            ans++;
                        }
                    }
                    
                }
            }
        }
    }
    cout << ans << endl;
    
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}