#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (char c = 'z'; c > 'a'; c--) {
        for (int i = 0; i < s.size(); i++) {
            if (c != s[i]) continue;
            if (i > 0 && s[i - 1] == c - 1 || i + 1 < s.size() && s[i + 1] == c - 1) {
                s.erase(i, 1);
                i = -1;
            }
        }
    }
    cout << n - s.size() << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}