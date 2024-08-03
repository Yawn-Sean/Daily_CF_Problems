#include <iostream>
#include <string>
using namespace std;

int yrlpSolve() {
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) return cout << ":(", 0;
    if (s[0] == ')' or s[n - 1] == '(') return cout << ":(", 0;
    int c = 0, t = 0;
    string ans = "";
    for (int i = 1; i < n - 1; i++) {
        if (s[i] != '?') {
            c += (s[i] == ')' ? -1 : 1);
        } else {
            c++, t++;
        }
        if (c < 0) return cout << ":(", 0;
        t = min(t, c);
    }
    if (c != 0 && (c & 1 || c / 2 > t)) return cout << ":(", 0;
    t = 0;
    for (int i = n - 2, j = 0; i >= 1; i--) {
        if (s[i] == '?') {
            if (j < c / 2) s[i] = ')', j++;
            else s[i] = '(';
        }
        if (s[i] == '(') t++;
        else t--;
        if (t > 0) return cout << ":(", 0;
    }
    s[0] = '(', s[n - 1] = ')';
    cout << s;
    return 0; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
