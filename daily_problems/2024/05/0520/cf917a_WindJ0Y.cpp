#include <bits/stdc++.h>
using namespace std;


void solve() {
    string str; cin >> str;
    int n = str.size();
    int ans = 0;

    for (int sp = 0; sp < n; sp ++) {
        int curv = 0;
        int qcnt = 0;
        auto add_c = [&](char c){
            if (c == '?') {
                curv --;
                qcnt ++;
            } else {
                if (c == '(') {
                    curv ++;
                } else {
                    curv --;
                }
            }
            if (curv < 0) {
                if (qcnt == 0) {
                    return false;
                }
                qcnt --;
                curv += 2;
            } 
            if (curv == 0) {
                ans ++;
            }
            return true;
        };
        for (int pos = sp; pos < n; pos ++) {
            if (!add_c(str[pos])) break;
        }
    }

    cout << ans << "\n";
}

int main(void) {
    
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T{1};
    // cin >> T;
    
    while (T--) {
        solve();
    }

}
