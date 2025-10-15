#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    /*
        [pre] @ [mid] . [suf]
    */
    string s;
    cin >> s;

    vector<int> at_pos, dot_pos;
    int n = s.size(); 
    for (int i = 0; i < n; i++) {
        if (s[i] == '@') {
            at_pos.push_back(i);
        } else if (s[i] == '.') {
            dot_pos.push_back(i);
        }
    }
    
    auto check1 = [](char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '_';
    };
    auto check2 = [](char c) {
        return (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9');
    };
    auto check3 = [](char c) {
        return c >= 'a' && c <= 'z';
    };

    i64 ans = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '@') {
            int l = i, cl = 0;
            while (l > 0 && check1(s[l - 1])) {
                l--;
                cl += check3(s[l]);
            }

            int r = i, cr = 0;
            while (r < n && check2(s[r + 1])) {
                r++;
            }

            if (r > i && r + 1 < n && s[r + 1] == '.') {
                r++;
                int nr = r, cr = 0;
                while (nr + 1 < n && check3(s[nr + 1])) {
                    nr++;
                    cr++;
                }

                ans += 1ll * cl * cr;
            }
        }
    }

    cout << ans << endl;
    return 0;
}
