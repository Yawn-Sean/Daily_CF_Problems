#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    string s = "aba";
    for (char c = 'c'; s.size() < n; c++) {
        string t = s;
        s.push_back(c);
        s += t;
    }
    cout << s.substr(0, n) << "\n";
    return 0;
}
