#include <iostream>
#include <string>
#include <climits>
using namespace std;

void yrlpSolve() {
    int n; cin >> n;
    string a, b; cin >> a >> b;
    int c[2][2] {};
    for (int i = 0; i < n; i++) c[a[i] - '0'][b[i] - '0']++;
    int ans = INT_MAX;
    if (c[1][1] - c[0][0] == 1) ans = c[0][0] + c[1][1];
    if (c[0][1] == c[1][0]) ans = min(ans, c[0][1] << 1); 
    cout << (ans == INT_MAX ? -1 : ans) << endl;
    return; 
}

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
