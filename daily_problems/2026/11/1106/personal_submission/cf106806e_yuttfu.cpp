#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    bool flag = true;
    for(int i = 0;i < n;i++){
        if(s[i] != s[i%1]) flag = false;
    }
    if(flag){
        cout << n << '\n';
        for(int i = 0;i < n;i++) cout << s[i] << ' ';
        cout << '\n';
        return;
    }
    for(int i = 2;i <= n/i;i++){
        if(n % i == 0){
            bool f1 = true,f2 = true;
            for(int j = 0;j < n;j++){
                if(s[j] != s[j%i]) f1 = false;
                if(s[j] != s[j%(n/i)]) f2 = false;
            }
            if(f1 || f2){
                cout << 2 << '\n';
                cout << s.substr(0,1) << ' ' << s.substr(1) << '\n';
                return;
            }
        }
    }
    cout << 1 << '\n' << s << '\n';
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
