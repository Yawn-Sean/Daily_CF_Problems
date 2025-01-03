/*
    注意到就八位数，直接全部试一遍
*/
#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    string s;
    cin >> s;
    int n = s.size();
    if (n == 1) {
        if (s == "0" || s == "X" || s == "_") cout << "1\n";
        else cout << "0\n";
        return;
    }
    if (s[0] == '0') {
        cout << "0\n";
        return;
    }
    int cur = 0;
    int ans = 0;
    
    auto check = [&](string ss) -> bool {
        int ok = 1;
        int f = 1;
        char cX;
        for (int i = 0; i < n; i++) {
            if (s[i] == '_') continue;
            if (s[i] == 'X') {
                if (f) {
                    cX = ss[i];
                    f = 0;
                    continue;
                } else {
                    if (cX != ss[i]) return false;
                    continue;
                }
            }
            if (ss[i] != s[i]) return false;
        }

        return true;
    };
    
    
    while (true) {
        string ss = to_string(cur);
        // cerr << ss << endl;
        if (ss.size() > n) break;
        if (ss.size() < n) {
            cur += 25;
            continue;
        }

        if (check(ss)) ans++;

        cur += 25;
    }
    cout << ans << "\n";
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t = 1;
    while (t--) {
       solve();
    }
    return 0;
}
