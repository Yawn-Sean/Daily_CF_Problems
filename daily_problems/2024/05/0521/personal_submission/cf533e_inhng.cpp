#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s, t;
    cin >> n >> s >> t;
    for (int i = 0; i < n; ++i) {
        if (s[i] != t[i]) {
            s = s.substr(i);
            t = t.substr(i);
            break;
        }
    }
    for (int i = s.size() - 1; ~i; --i) {
        if (s[i] != t[i]) {
            s = s.substr(0, i + 1);
            t = t.substr(0, i + 1);
            break;
        }
    }
    cout << (s.substr(1) == t.substr(0, t.size() - 1)) + (t.substr(1) == s.substr(0, s.size() - 1)) << endl;
    return 0;
}
