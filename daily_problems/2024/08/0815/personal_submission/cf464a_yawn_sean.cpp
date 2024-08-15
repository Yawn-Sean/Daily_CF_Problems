#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include <bits/extc++.h>
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;
using namespace std;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;
    cin >> n >> p;

    string s;
    cin >> s;

    char ma = 'a' + p;

    for (int i = n - 1; i >= 0; i --) {
        for (char c = s[i] + 1; c < ma; c ++) {
            bool flg = true;
            for (int j = 1; j <= 2; j ++) {
                if (i - j >= 0 && s[i - j] == c) flg = false;
            }
            if (flg) {
                s[i] = c;
                for (int idx = i + 1; idx < n; idx ++) {
                    for (char nc = 'a'; nc < ma; nc ++) {
                        flg = true;
                        for (int nj = 1; nj <= 2; nj ++) {
                            if (idx - nj >= 0 && s[idx - nj] == nc) flg = false;
                        }
                        if (flg) {
                            s[idx] = nc;
                            break;
                        }
                    }
                }
                cout << s;
                return 0;
            }
        }
    }
    cout << "NO";

    return 0;
}