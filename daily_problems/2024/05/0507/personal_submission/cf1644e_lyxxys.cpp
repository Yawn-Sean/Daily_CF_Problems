#include <bits/stdc++.h>
using namespace std;
using ll = long  long;
using Pii = pair<int,int>;
const int INF = 2e9;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int len = s.size();
    int pos = -1;
    for (int i = 0; i < len; ++ i)
        if (s[i] != s[0]){
            pos = i;
            break;
        }

    if (pos == -1){
        cout << n << "\n";
        return;
    }

    ll res = pos + 1ll* (n-pos) * n;
    ll a = 0, b = 0;
    for (int i = pos; i < len; ++ i)
        if (s[i] == 'R') ++ a;
        else ++ b;
    
    cout << res - a*b << "\n";
}
