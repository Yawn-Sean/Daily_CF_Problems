#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using ull = unsigned long long;
const int N = 1011, P = 1e9+7, inf = 1e9;

void solve(){
    int n;
    string s;
    cin >> n >> s;
    vector <int> f(n+1);
    s = " " + s;
    int len = s.size()-1, ct = n/2;
    for (int i = 1; i <= len; ++ i)
        if (s[i] == '(') -- ct;
    bool flg = false;
    for (int i = 1, lst = 0; i <= len; ++ i){
        if (s[i] == '?'){
            if (ct >= 1) -- ct, ++ lst, f[i] = 1;
            else -- lst, f[i] = -1;
        } else if (s[i] == '(') ++ lst;
        else -- lst;

        if (i < len && lst <= 0 || i==len && lst != 0){
            flg = true;
            break;
        }
    }
    if (flg){
        cout << ":(\n";
        return;
    }
    for (int i = 1; i <= n; ++ i){
        if (s[i] != '?') cout << s[i];
        else cout << (f[i]==1 ? '(' : ')');
    }
}
