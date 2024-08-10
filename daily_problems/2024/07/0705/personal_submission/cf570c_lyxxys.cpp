#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1050, mod = 1e9+7, inf = 1e9;

void solve(){
    int n, m;
    string s;
    cin >> n >> m;
    cin >> s;
    s = "@" + s + "@";
    int res = 0;

    for (int i = 1; i <= n; ++ i){
        if (s[i]=='.'){
            while (s[i]=='.') ++ i, ++ res;
            -- res;
        }
    }

    for (int i = 1; i <= m; ++ i){
        int loc;
        char ch;
        cin >> loc >> ch;
        if (ch != '.' && s[loc] == '.'){
            if (s[loc-1]=='.' && s[loc+1]=='.') res -= 2;
            else if (s[loc-1]=='.' || s[loc+1]=='.') -- res;
        } else if (ch == '.' && s[loc] != '.'){
            if (s[loc-1]=='.') ++ res;
            if (s[loc+1]=='.') ++ res;
        }
        s[loc] = ch;
        cout << res << "\n";
    }
}

