#include <iostream>
#include <vector>
#include <string>
using namespace std;

void yrlpSolve() {
    string s; cin >> s;
    int n = s.size();
    vector<int> cnt(n);
    for (int i = 1; i < n; i++) {
        if (s[i - 1] == '0') cnt[i] = cnt[i - 1] + 1;
        else cnt[i] = 0;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') continue;
        int num = 1; ans += 1;
        for (int j = i + 1; j < n and j - i < 20; j++) {
            num = num << 1 | (s[j] - '0');
            if (cnt[i] >= num - (j - i + 1)) ans += 1;
        }
    }
    cout << ans << endl;
}   

signed main() {
    int T = 1; cin >> T;
    while (T--) yrlpSolve();
}
