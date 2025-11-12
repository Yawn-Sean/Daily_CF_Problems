#include <bits/stdc++.h>
using namespace std;
#define endl '\n'



void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    while (*(s.end() - 1) == '?') s.pop_back();
    reverse(s.begin(), s.end());
    while (*(s.end() - 1) == '?') s.pop_back();
    int ans = 0;
    int cnt = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '?') cnt++;
        else {
            ans++;
            if (cnt == 1 && s[i] != s[i - 2]) ans++;
            else if (cnt > 1) ans++;
            cnt = 0;
        }
    }
    cout << ans << endl;
}

signed main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int _T = 1;
    cin >> _T;
    while (_T--){ 
        solve();
    }
    return 0;
}