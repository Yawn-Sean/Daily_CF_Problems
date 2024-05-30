#include <bits/stdc++.h>
using ll = long long;
using namespace std;
int f[3050][3050];

void solve(){
    string s;
    cin >> s;

    int n = s.size();

    if (n < 3000){
        s = " " + s;
        for (int len = 1; len <= n; ++ len)
            for (int l = 1; l+len-1 <= n; ++ l){
                if (len == 1) f[l][l] = 1;
                else {
                    int r = l+len-1;
                    if (s[l] == s[r]) f[l][r] = f[l+1][r-1] + 2;
                    else f[l][r] = max(f[l+1][r], f[l][r-1]);
                }
            }

        string ans;
        int l = 1, r = n;
        while (l < r){
            if (s[l] == s[r]){
                ans += s[l];
                ++ l, -- r;
            } else {
                if (f[l+1][r] == f[l][r]) ++ l;
                else -- r;
            }
        }
        int flag = 1;
        if (ans.size() >= 50) ans = ans.substr(0, 50), flag = 0;
        string extra = ans;
        reverse(extra.begin(), extra.end());
        ans += (l==r && flag) ? s[l]+extra : extra;
        cout << ans << "\n";
    } else {
        int cnt[26] = {0};
        for (int i = 0; i < n; ++ i) {
            ++cnt[s[i] - '0'];
            if (cnt[s[i] - '0'] == 100) {
                for (int j = 0; j < 100; ++j) cout << s[i];
                cout << "\n";
                return;
            }
        }
    }
    return;
}
