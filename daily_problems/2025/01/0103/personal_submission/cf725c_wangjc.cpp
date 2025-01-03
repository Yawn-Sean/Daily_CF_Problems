#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
    string s;
    cin >> s;
    vector<int> mark(305, -1); 
    char ans[31][2];          
    int a = -1, b = -1;     

    for (int i = 0; i <= 26; i++) {
        if (i <= 25 && s[i] == s[i + 1]) {
            cout << "Impossible\n";
            return;
        }
        if (mark[s[i]] != -1) {
            a = mark[s[i]];
            b = i;
        } else {
            mark[s[i]] = i;
        }
    }

    while (a > 26 - b) {
        s += s[0];
        s.erase(s.begin());
        a--;
        b--;
    }
    while (a < 25 - b) {
        s = s.back() + s;
        s.pop_back();
        a++;
        b++;
    }

    for (int i = 0; i < 13; i++) {
        ans[i][1] = s[i];
    }

    int j = 13;
    for (int i = 12; i >= 0; i--, j++) {
        if (ans[i][1] == s[j] || ans[i + 1][1] == s[j]) {
            j++;
        }
        ans[i][0] = s[j];
    }

    for (int i = 0; i < 13; i++) {
        cout << ans[i][0];
    }
    cout << '\n';
    for (int i = 0; i < 13; i++) {
        cout << ans[i][1];
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    while (t--) {
        solve();
    }
    return 0;
}
