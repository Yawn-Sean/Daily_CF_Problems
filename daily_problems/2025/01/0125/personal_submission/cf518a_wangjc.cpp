#include <bits/stdc++.h>
#define int long long
using namespace std;


void solve(){
    string s, t;
    cin >> s >> t;
    int over = -1;
    for (int i = s.size() - 1; i >= 0; i--) {
        if (s[i] != 'z') {
            over = i;
            break;
        }
    }
    int n = s.size();
    s[over]++;
    s = s.substr(0, over + 1);
    s.append(string(n - over - 1, 'a'));
    if (s == t) {
        cout << "No such string\n";
    } else {
        cout << s << endl;
    }
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
