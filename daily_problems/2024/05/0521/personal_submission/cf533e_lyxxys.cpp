#include <bits/stdc++.h>
using ll = long long;
using namespace std;

void solve(){
    int n;
    string s1, s2;
    cin >> n >> s1 >> s2;

    int res = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; ++ i)
        if (s1[i] != s2[i]){
            if (l == -1) l = i;
            r = i;
        }
    int len = r-l;
    if (l != -1){
        if (s1.substr(l, len) == s2.substr(l+1, len)) ++ res;  //分别去头和去尾
        if (s2.substr(l, len) == s1.substr(l+1, len)) ++ res;
    }
    cout << res << "\n";
}

