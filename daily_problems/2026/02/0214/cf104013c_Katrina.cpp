#include <bits/stdc++.h>
using namespace std;
using ll = long long;

string ask(int i, int j) {
    cout << i << ' ' << j << endl;
    string s; cin >> s; return s;
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 1; j < n ; ++j) {
            string s = ask(j, j + 1);
            if (s == "WIN") return;
        }
        for (int j = n; j > 1; --j) {
            string s = ask(j - 1, j);
            if (s == "WIN") return;
        }
    }
}

signed main() {  
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(12);

    int T = 1;
    // cin >> T;  
    while (T--) solve();    
    return 0;
} 
