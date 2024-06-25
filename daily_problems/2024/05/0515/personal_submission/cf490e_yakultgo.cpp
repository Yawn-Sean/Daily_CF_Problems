#include <bits/stdc++.h>

using namespace std;

string s[100005], s1;
int n, ans[100005];

int to (int len) {
    int ans = 0;
    for (int i = 0; i < len; ++ i) {
        ans = 10 * ans + s1[i];
    }
    return ans;
}

int main() {

    cin >> n;
    for (int i = 1; i <= n; ++ i) {
        cin >> s[i];
    }

    for (int i = 1; i <= n; ++ i) {
        for (int j = 0; j < (int)s[i].size(); ++ j) {
            if(s[i][j] == '?') s1[j] = 9;
            else s1[j] = s[i][j] - '0';
        }
        if (to(s[i].size()) <= ans[i - 1]){
            cout << "NO\n";
            return 0;
        }

        for (int j = 0; j < (int)s[i].size(); ++ j){
            if (s[i][j] == '?'){
                for (int k = 8; k >= 0; -- k){
                    if (!j && !k) {
                        break;
                    }

                    s1[j] = k;
                    if (to((int)s[i].size()) <= ans[i-1]){
                        s1[j] = k + 1;
                        break;
                    }
                }
            }
        }
        ans[i] = to((int)s[i].size());
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++ i) {
        cout << ans[i] << "\n";
    }
    cout << "\n";
    return 0;
}
