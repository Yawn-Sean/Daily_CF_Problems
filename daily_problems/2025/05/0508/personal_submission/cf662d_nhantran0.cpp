/*
 https://codeforces.com/problemset/problem/662/D
 D. International Olympiad
 Solver: nhant
 2025-05-09 09:22:53
 https://codeforces.com/problemset/submission/662/318888132
*/
#include <bits/stdc++.h>

using namespace std;

string prefix_of(string& s) {
    int n = (int) s.size();
    if (n == 1) {
        return s.compare("9") >= 0 ? "198" : "199";
    } else if (n == 2) {
        return s.compare("99") >= 0 ? "19" : "20";
    } else if (n == 3) {
        return s.compare("099") >= 0 ? "2" : "3";
    } else {
        string u = "9903";
        while ((int) u.size() < n) {
            u += '1';
        }
        reverse(u.begin(), u.end());
        return s.compare(u) >= 0 ? "" : "1";
    }
}

void solve() {
    string s;
    cin >> s;
    s = s.substr(s.find('\'') + 1);
    cout << prefix_of(s) << s << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        solve();
    }
}
