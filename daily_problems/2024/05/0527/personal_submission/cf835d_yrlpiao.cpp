#include <iostream>
#include <string>
#include <vector>
using namespace std;

int mp[5050][5050];
void yrlpSolve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> ans(n, 0); ans[0] = n;

    for (int i = 0; i < n; i++) mp[i][i] = 1, mp[i + 1][i] = 1;

    for (int len = 2; len <= n; len++) {
        for (int i = 0, j = i + len - 1; j < n; i++, j++) {
            if (s[i] == s[j] && mp[i + 1][j - 1]) {
                mp[i][j] = mp[i][(i + j - 1) / 2] + 1;
                ans[mp[i][j] - 1] += 1;
            }
        }
    }
    for (int i = n - 2; i >= 0; i--) ans[i] += ans[i + 1];
    for (int i : ans) cout << i << " ";
    return; 
}    

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
