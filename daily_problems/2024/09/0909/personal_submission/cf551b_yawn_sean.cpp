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

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> cnt_a(26, 0), cnt_b(26, 0), cnt_c(26, 0);
    for (auto ch: a) cnt_a[ch - 'a'] ++;
    for (auto ch: b) cnt_b[ch - 'a'] ++;
    for (auto ch: c) cnt_c[ch - 'a'] ++;

    int x = 0, y = 0;
    for (int i = 0; i * b.size() < a.size(); i ++) {
        bool flg = true;
        int cnt = a.size();
        for (int j = 0; j < 26; j ++) {
            if (cnt_a[j] < cnt_b[j] * i) {
                flg = false;
                break;
            }
            if (cnt_c[j]) cnt = min(cnt, (cnt_a[j] - cnt_b[j] * i) / cnt_c[j]);
        }
        if (!flg) break;
        if (i + cnt > x + y) x = i, y = cnt;
    }
    for (int i = 0; i < x; i ++) cout << b;
    for (int i = 0; i < y; i ++) cout << c;
    for (int i = 0; i < 26; i ++)  cout << string(cnt_a[i] - cnt_b[i] * x - cnt_c[i] * y, 'a' + i);

    return 0;
}